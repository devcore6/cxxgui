#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
	void window_t::render(
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
        window = SDL_CreateWindow(title, (int)pos_x, (int)pos_y, (int)width, (int)height, flags | SDL_WINDOW_OPENGL);
        if(!window) exit(EXIT_FAILURE);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(!renderer) exit(EXIT_FAILURE);

        context = SDL_GL_CreateContext(window);
        if(!renderer) exit(EXIT_FAILURE);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        glShadeModel(GL_SMOOTH);
        glEnable(GL_MULTISAMPLE);
        glDisable(GL_DEPTH_TEST);

        glClearColor(0, 0, 0, 1.0);

        SDL_SetWindowResizable(window, SDL_TRUE);
        SDL_SetWindowOpacity(window, opacity);
        SDL_StopTextInput();

        running = true;
        started = true;

        content->style.background_color = color::background();
        content->style.color = color::foreground();

        content->style.width  = width
                              - content->style.margin_left
                              - content->style.border_left.stroke
                              - content->style.padding_left
                              - content->style.padding_right
                              - content->style.border_right.stroke
                              - content->style.margin_right;
                                                      
        content->style.height = height
                              - content->style.margin_top
                              - content->style.border_top.stroke
                              - content->style.padding_top
                              - content->style.padding_bottom
                              - content->style.border_bottom.stroke
                              - content->style.margin_bottom;

        [this, event_handler, pos_x, pos_y, main_loop, data]() { // Lambda to allow us to break through both loops at once
            size_t x = pos_x, y = pos_y;

            int w, h;
            SDL_GetWindowSize(window, &w, &h);

            while(true) {
                glClear(GL_COLOR_BUFFER_BIT);

                glLoadIdentity();

                glViewport(0, 0, w, h);

                gluOrtho2D(0.0, w, h, 0.0);

                if(!main_loop(this, data)) return;

                glBegin(GL_QUADS);
                    glColor4f(
                        (float)(content->style.background_color >> 24 & 0xFF) / 255.0f,
                        (float)(content->style.background_color >> 16 & 0xFF) / 255.0f,
                        (float)(content->style.background_color >> 8  & 0xFF) / 255.0f,
                        (float)(content->style.background_color       & 0xFF) / 255.0f
                    );

                    glVertex2f(0.0f, 0.0f);
                    glVertex2f(w, 0.0f);
                    glVertex2f(w, h);
                    glVertex2f(0.0f, h);
                glEnd();

                glPushMatrix();
                    content->render();
                glPopMatrix();

                glFlush();
                SDL_GL_SwapWindow(window);

                SDL_Event e;
                while(SDL_PollEvent(&e) != 0) {
                    switch(e.type) {
                        case SDL_QUIT: return;

                        case SDL_WINDOWEVENT: {

                            if(e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                                w = e.window.data1;
                                h = e.window.data2;

                                content->style.width  = (float)e.window.data1
                                                      - content->style.margin_left
                                                      - content->style.border_left.stroke
                                                      - content->style.padding_left
                                                      - content->style.padding_right
                                                      - content->style.border_right.stroke
                                                      - content->style.margin_right;
                                                      
                                content->style.height = (float)e.window.data2
                                                      - content->style.margin_top
                                                      - content->style.border_top.stroke
                                                      - content->style.padding_top
                                                      - content->style.padding_bottom
                                                      - content->style.border_bottom.stroke
                                                      - content->style.margin_bottom;
                            }

                            [[fallthrough]];

                        }

                        default: event_handler(e); break;
                    }
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(4));
            }
        }();

        SDL_GL_DeleteContext(context);
        context = nullptr;

        SDL_DestroyRenderer(renderer);
        renderer = nullptr;

        SDL_DestroyWindow(window);
        window = nullptr;

        running = false;
    }
}