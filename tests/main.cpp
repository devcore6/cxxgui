#include <iostream>
#include <thread>
#include <chrono>

#include <cstdlib>

#include <cxxgui/cxxgui.hpp>

struct content_view : cxxgui::view {
    content_view() {
        data = cxxgui::hstack({
            []() -> cxxgui::view* {
                cxxgui::view* view = new cxxgui::view();

                view->data = cxxgui::vstack({
                    []() -> cxxgui::text* {
                        cxxgui::text* text = new cxxgui::text("Hello World!", "SF Pro Text", 64, 400);

                        text->style.border_top = 1;
                        text->style.border_right = 1;
                        text->style.border_bottom = 1;
                        text->style.border_left = 1;
                        text->style.margin_bottom = 16;

                        return text;
                    }(),

                    []() -> cxxgui::text* {
                        cxxgui::text* text = new cxxgui::text("This is kinda cool!", "SF Pro Text", 32, 400);

                        text->style.border_top = 1;
                        text->style.border_right = 1;
                        text->style.border_bottom = 1;
                        text->style.border_left = 1;
                        text->style.margin_top = 16;
                        text->style.background_color = 0x444444FF;

                        return text;
                    }()
                });

                view->style.border_top = 1;
                view->style.border_right = 1;
                view->style.border_bottom = 1;
                view->style.border_left = 1;
                view->style.margin_right = 16;
                view->style.background_color = 0x222222FF;

                return view;
            }(),
            
            []() -> cxxgui::view* {
                cxxgui::view* view = new cxxgui::view();

                view->data = cxxgui::vstack({
                    []() -> cxxgui::text* {
                        cxxgui::text* text = new cxxgui::text("Pretty cool, huh?", "SF Pro Text", 48, 400);

                        text->style.border_top = 1;
                        text->style.border_right = 1;
                        text->style.border_bottom = 1;
                        text->style.border_left = 1;
                        text->style.color = 0xFF8800FF;

                        return text;
                    }()
                });

                view->style.border_top = 1;
                view->style.border_right = 1;
                view->style.border_bottom = 1;
                view->style.border_left = 1;
                view->style.margin_left = 16;
                view->style.background_color = 0x12345678;

                return view;
            }()
        });

        style.horizontal_align = cxxgui::align::right;
        style.margin_right = 32;
        style.background_color = 0x87654321;
    }
};

int main(int argc, char* argv[]) {
    cxxgui::init();

    cxxgui::try_register_font_path("SF Pro Text", 400, "fonts/SF-Pro-Text-Regular.ttf");

    cxxgui::window_t window = cxxgui::window_t(
        "Test",
        200,
        200,
        1280,
        720,
        SDL_WINDOW_SHOWN,
        new content_view(),
        [](SDL_Event e) { },
        0.95f,
        false
    );

    return 0;
}
