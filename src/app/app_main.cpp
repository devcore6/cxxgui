#include <string>
#include <vector>
#include <initializer_list>
#include <functional>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#ifdef __APPLE__
# include <OpenGL/glu.h>
#else
# include <gl/GLU.h>
#endif

#include <cxxgui/device-defs.hpp>
#include <cxxgui/color.hpp>
#include <cxxgui/style.hpp>
#include <cxxgui/view.hpp>
#include <cxxgui/window.hpp>
#include <cxxgui/app.hpp>

namespace cxxgui {
    void app::main() {
        if(body == nullptr) {
            std::cerr << "app body must not be nullptr" << std::endl;
            exit(EXIT_FAILURE);
        }

#ifdef __CXXGUI_DESKTOP__
        window_t window = window_t(
            title.c_str(),
            width,
            height,
            body,
            0,
            event_handler,
            refresh_rate,
            opacity,
            main_loop,
            data
        );
#endif
    }
    app::~app() {
#ifdef __CXXGUI_DESKTOP__

#endif
    }
}
