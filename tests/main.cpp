#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class content_view : public view {
public:
    content_view() {
        body = new vstack {
            (new image("../cxxgui.png"))
                ->resizable(true)
                ->frame(0.0f, 960.0f, 0.0f, 0.0f, 480.0f, 0.0f, alignment_t::center)
                ->hover_background_color(color::evergreen)
                ->active_background_color(color::sapphire)
                ->on_hover([](view* v, void* data) {
                    std::cout << "Entered focus" << std::endl;
                })
                ->on_leave([](view* v, void* data) {
                    std::cout << "Left focus" << std::endl;
                })
                ->on_click([](view* v, void* data) {
                    std::cout << "Clicked" << std::endl;
                }),
            new hstack {
                (new text("Writing GUI code"))
                    ->font(large_title),
                (new text(" has never been this easy"))
                    ->font(title)
                    ->foreground_color(color::cyan)
                    ->margin(6.0f, 0.0f, 0.0f, 0.0f)
            },
            new hstack {
                symbols::warning_thin()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_extralight()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_light()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_medium()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_semibold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_bold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_extrabold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_black()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64),
                symbols::warning_fill()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_orange)
                    ->size(64)
            },
            new hstack {
                symbols::circle_inset_thin()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::safety_yellow)
                    ->size(64),
                symbols::circle_inset_extralight()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::blue)
                    ->size(64),
                symbols::circle_inset_light()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::crimson)
                    ->size(64),
                symbols::circle_inset()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::indigo)
                    ->size(64),
                symbols::circle_inset_medium()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::lemon_yellow)
                    ->size(64),
                symbols::circle_inset_semibold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::tangerine)
                    ->size(64),
                symbols::circle_inset_bold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::green)
                    ->secondary_color(color::peach)
                    ->size(64),
                symbols::circle_inset_extrabold()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::white)
                    ->secondary_color(color::brown)
                    ->size(64),
                symbols::circle_inset_black()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::accent_color)
                    ->secondary_color(color::evergreen)
                    ->size(64),
                symbols::circle_fill()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette)
                    ->primary_color(color::safety_yellow)
                    ->size(64)
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
        [](SDL_Event e) { }
    );

    return 0;
}
