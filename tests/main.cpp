#include <iostream>
#include <thread>
#include <chrono>

#include <cstdlib>

#include <cxxgui/cxxgui.hpp>

int main(int argc, char* argv[]) {
    cxxgui::view view;

    cxxgui::window_t window = cxxgui::window_t(
        "Test",
        200,
        200,
        1280,
        720,
        SDL_WINDOW_SHOWN,
        view,
        [](SDL_Event e) { },
        false
    );

    return 0;
}
