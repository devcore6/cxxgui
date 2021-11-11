#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class content_view : public view {
public:
    content_view() {
        body = new vstack {
            new hstack {
                (new toggle(100, [](bool state) {})),
                (new toggle(200, [](bool state) {})),
                (new toggle(300, [](bool state) {})),
                (new toggle(400, [](bool state) {})),
                (new toggle(500, [](bool state) {})),
                (new toggle(600, [](bool state) {})),
                (new toggle(700, [](bool state) {})),
                (new toggle(800, [](bool state) {})),
                (new toggle(900, [](bool state) {})),
                (new toggle(0, [](bool state) {}))
            },
            new hstack {
                (new toggle(100, true, [](bool state) {})),
                (new toggle(200, true, [](bool state) {})),
                (new toggle(300, true, [](bool state) {})),
                (new toggle(400, true, [](bool state) {})),
                (new toggle(500, true, [](bool state) {})),
                (new toggle(600, true, [](bool state) {})),
                (new toggle(700, true, [](bool state) {})),
                (new toggle(800, true, [](bool state) {})),
                (new toggle(900, true, [](bool state) {})),
                (new toggle(0, true, [](bool state) {}))
            }
        };
    }
};

int main(int argc, char* argv[]) {

    window_t window = window_t(
        "CXXGUI Test",
        1280,
        720,
        new content_view
    );

    return 0;
}
