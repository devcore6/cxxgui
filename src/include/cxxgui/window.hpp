#pragma once
#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    class window_t;

    extern bool null_function(window_t*, void*);
    extern void null_handler(SDL_Event e);

    class window_t {
    public:
        view* content = nullptr;

    private:
        friend class view;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_GLContext context = nullptr;

        bool running = false;
        bool started = false;

        void render(
            const char* title,
            size_t pos_x,
            size_t pos_y,
            size_t width,
            size_t height,
            uint32_t flags,
            uint16_t refresh_rate,
            float opacity,
            std::function<void(SDL_Event)> event_handler,
            std::function<bool(window_t*, void*)> main_loop,
            void* data
        );

    public:

        window_t(
            const char* title,
            size_t width,
            size_t height,
            view* v,
            uint32_t flags = 0,
            std::function<void(SDL_Event)> event_handler = null_handler,
            uint16_t refresh_rate = 60,
            float opacity = 1.0f,
            std::function<bool(window_t*, void*)> main_loop = null_function,
            void* data = nullptr
        ) : content(v) {
            content->style.width = (float)width;
            content->style.height = (float)height;

            render(
                title,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                SDL_WINDOW_SHOWN | flags,
                refresh_rate,
                opacity,
                event_handler,
                main_loop,
                data
            );
        }

        ~window_t() {
            delete content;
            if(context) SDL_GL_DeleteContext(context);
            if(renderer) SDL_DestroyRenderer(renderer);
            if(window) SDL_DestroyWindow(window);
        }
    };
}
