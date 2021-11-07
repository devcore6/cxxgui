#include <cxxgui/cxxgui.hpp>

using namespace cxxgui;

class content_view : public view {
public:
    content_view() {
        body = new vstack {
            (new image("../cxxgui.png"))
                ->resizable(true)
                ->frame(0.0f, 960.0f, 0.0f, 0.0f, 480.0f, 0.0f, alignment_t::center),
            new hstack {
                (new text("Writing GUI code"))
                    ->font(large_title),
                (new text(" has never been this easy"))
                    ->font(title)
                    ->foreground_color(color::cyan)
                    ->margin(6.0f, 0.0f, 0.0f, 0.0f)
            }
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
        [](SDL_Event e) { },
        0.95f
    );

    return 0;
}
