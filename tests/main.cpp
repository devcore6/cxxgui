#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class content_view : public view {
public:
    content_view() {
        body = new vstack {
            new toggle(0, [](bool state) { std::cout << std::boolalpha << state << std::endl; }),
            new toggle(0, true, [](bool state) { std::cout << std::boolalpha << state << std::endl; })
        };
    }
};

int main(int argc, char* argv[]) {

    window_t window = window_t(
        "CXXGUI Test",
        200,
        200,
        1280,
        720,
        SDL_WINDOW_SHOWN,
        new content_view,
        [](SDL_Event e) {}
    );

    return 0;
}
