#include <iostream>
#include <thread>
#include <chrono>

#include <cstdlib>

#include <cxxgui/cxxgui.hpp>

using namespace cxxgui;

class content_view : public view {
public:
    content_view() {
        body = new hstack {
            (new vstack {
                (new text("We're no strangers to love"))
                    ->font(monospace)
                    ->font_size(12),

                (new text("You know the rules, and so do I"))
                    ->font(monospace)
                    ->font_size(12),

                (new text("A full commitment's what I'm thinking of"))
                    ->font(monospace)
                    ->font_size(12),

                (new text("You wouldn't get this from any other guy"))
                    ->font(monospace)
                    ->foreground_color(0xFFAA00FF)
            })
                ->margin(0.0f, 16.0f, 0.0f, 0.0f),

            (new vstack {
                (new text("Title"))
                    ->font(title),

                (new text("Body aligned left"))
                    ->border({ 1.0f, 0xFFFFFFFF },
                             { 0.0f, 0x00000000 },
                             { 0.0f, 0x00000000 },
                             { 0.0f, 0x00000000 })
                    ->margin(8.0f, 0.0f)
                    ->padding(8.0f, 0.0f)
                    ->frame(300.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::leading)
                    ->background_color(0x12345678),

                (new text("Body aligned right"))
                    ->border({ 0.0f, 0x00000000 },
                             { 0.0f, 0x00000000 },
                             { 1.0f, 0xFFFFFFFF },
                             { 0.0f, 0x00000000 })
                    ->margin(8.0f, 0.0f)
                    ->padding(8.0f, 0.0f)
                    ->frame(300.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::trailing),

                (new text("Large title"))
                    ->font(large_title),

                (new text("Headline"))
                    ->font(headline),

                (new text("Subheadline"))
                    ->font(subheadline),

                (new text("Monospaced"))
                    ->font(monospace)
            })
                ->margin(0.0f, 0.0f, 0.0f, 16.0f)
                ->padding(0.0f, 0.0f, 0.0f, 16.0f)
                ->border({ 0.0f, 0x00000000 },
                         { 0.0f, 0x00000000 },
                         { 0.0f, 0x00000000 },
                         { 1.0f, 0xFFFFFFFF })
        };
    }
};

int main(int argc, char* argv[]) {
    window_t window = window_t(
        "Test",
        200,
        200,
        1280,
        720,
        SDL_WINDOW_SHOWN,
        (new content_view)
            ->margin(32)
            ->padding(32)
            ->border({ 1, 0xFFFFFFFF })
            ->frame(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::bottom_trailing),
        [](SDL_Event e) { },
        0.95f
    );

    return 0;
}
