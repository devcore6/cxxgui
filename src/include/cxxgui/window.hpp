#pragma once
#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    class window_t;

    extern bool null_function(window_t*, void*);

    class window_t {
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_GLContext context = nullptr;

        std::thread thread;
        std::promise<void> shut_down;
        std::mutex lock;

        view* content;

        bool running = false;
        bool started = false;

        const bool is_async;

        static void renderer_thread(
            window_t* ptr,
            const char* title,
            size_t pos_x,
            size_t pos_y,
            size_t width,
            size_t height,
            uint32_t flags,
            float opacity,
            std::function<void(SDL_Event)> event_handler,
            std::function<bool(window_t*, void*)> main_loop,
            void* data
        ) {
            ptr->window = SDL_CreateWindow(title, pos_x, pos_y, width, height, flags | SDL_WINDOW_OPENGL);
            if(!ptr->window) exit(EXIT_FAILURE);

            ptr->renderer = SDL_CreateRenderer(ptr->window, -1, SDL_RENDERER_ACCELERATED);
            if(!ptr->renderer) exit(EXIT_FAILURE);

            ptr->context = SDL_GL_CreateContext(ptr->window);
            if(!ptr->renderer) exit(EXIT_FAILURE);

            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);

            glShadeModel(GL_SMOOTH);
            glEnable(GL_MULTISAMPLE);
            glDisable(GL_DEPTH_TEST);
            glEnable(GL_SCISSOR_TEST);

            glClearColor(0, 0, 0, 1.0);

            SDL_SetWindowResizable(ptr->window, SDL_TRUE);
            SDL_SetWindowOpacity(ptr->window, opacity);
            SDL_StopTextInput();

            ptr->running = true;
            ptr->started = true;

            [ptr, event_handler, pos_x, pos_y, main_loop, data]() { // Lambda to allow us to break through both loops at once
                std::future<void> shut_down = ptr->shut_down.get_future();

                bool dragging_window = false;
                bool pressing_minimize = false;
                bool pressing_maximize = false;
                bool pressing_close = false;

                size_t x = pos_x, y = pos_y;

                int w, h;
                SDL_GetWindowSize(ptr->window, &w, &h);

                ptr->content->init();

                while(shut_down.wait_for(std::chrono::milliseconds(1000 / (ptr->refresh_rate > 0 ? ptr->refresh_rate : 1))) == std::future_status::timeout) {
                    glClear(GL_COLOR_BUFFER_BIT);

                    glLoadIdentity();

                    gluOrtho2D(0.0, w, h, 0.0);

                    if(!main_loop(ptr, data)) return;

                    glPushMatrix();
                        ptr->lock.lock();
                        ptr->content->render();
                        ptr->lock.unlock();
                    glPopMatrix();

                    glFlush();
                    SDL_GL_SwapWindow(ptr->window);

                    SDL_Event e;
                    while(SDL_PollEvent(&e) != 0) {
                        switch(e.type) {
                            case SDL_QUIT: return;

                            case SDL_WINDOWEVENT: {

                                if(e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                                    ptr->content->style.width = e.window.data1;
                                    ptr->content->style.height = e.window.data2;
                                    ptr->content->style.translate_y = h - e.window.data2;
                                }

                                [[fallthrough]];

                            }

                            default: event_handler(e); break;
                        }
                    }
                }
            }();

            SDL_GL_DeleteContext(ptr->context);
            ptr->context = nullptr;

            SDL_DestroyRenderer(ptr->renderer);
            ptr->renderer = nullptr;

            SDL_DestroyWindow(ptr->window);
            ptr->window = nullptr;

            ptr->running = false;
        }

    public:

        size_t refresh_rate = 60;

        void quit() { shut_down.set_value(); }

        bool is_open() { return running; }

        void set_view(view* c) {
            lock.lock();
            content = c;
            lock.unlock();
        }

        window_t(
            const char* title,
            size_t pos_x,
            size_t pos_y,
            size_t width,
            size_t height,
            uint32_t flags,
            view* v,
            std::function<void(SDL_Event)> event_handler,
            float opacity = 1.0f,
            bool async = true,
            std::function<bool(window_t*, void*)> main_loop = null_function,
            void* data = nullptr
        ) : content(v),
            is_async(async) {

            content->style.width = width;
            content->style.height = height;

            if(!async) {
                renderer_thread(
                    this,
                    title,
                    pos_x,
                    pos_y,
                    width,
                    height,
                    flags,
                    opacity,
                    event_handler,
                    main_loop,
                    data
                );
            } else {
                thread = std::thread(
                    window_t::renderer_thread,
                    this,
                    title,
                    pos_x,
                    pos_y,
                    width,
                    height,
                    flags,
                    opacity,
                    event_handler,
                    main_loop,
                    data
                );
                while(!started) {} // Wait until the window is actually open
            }
        }

        ~window_t() {
            if(is_async) thread.join();
            if(context) SDL_GL_DeleteContext(context);
            if(renderer) SDL_DestroyRenderer(renderer);
            if(window) SDL_DestroyWindow(window);
        }
    };

    inline void init() {
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) exit(EXIT_FAILURE);
        atexit(SDL_Quit);

        if(TTF_Init() < 0) exit(EXIT_FAILURE);
        atexit(TTF_Quit);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    }
}
