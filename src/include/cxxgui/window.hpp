#pragma once
#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    class window_t;

    extern bool null_function(window_t*, void*);

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
            float opacity,
            std::function<void(SDL_Event)> event_handler,
            std::function<bool(window_t*, void*)> main_loop,
            void* data
        );

    public:

        size_t refresh_rate = 60;

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
            std::function<bool(window_t*, void*)> main_loop = null_function,
            void* data = nullptr
        ) : content(v) {
            content->style.width = (float)width;
            content->style.height = (float)height;

            render(
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
        }

        ~window_t() {
            if(context) SDL_GL_DeleteContext(context);
            if(renderer) SDL_DestroyRenderer(renderer);
            if(window) SDL_DestroyWindow(window);
        }
    };
}
