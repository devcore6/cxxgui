#include <string>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <sstream>
#include <functional>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include <cxxgui/utilities.hpp>
#include <cxxgui/settings.hpp>
#include <cxxgui/color.hpp>
#include <cxxgui/style.hpp>
#include <cxxgui/view.hpp>
#include <cxxgui/animation.hpp>
#include <cxxgui/symbols.hpp>
#include <cxxgui/symbols_list.hpp>
#include <cxxgui/input.hpp> 

namespace cxxgui {

    void toggle::toggle_action(view* v, float x, float y, void* n) {
        toggle* self = dynamic_cast<toggle*>(v);
        self->state = !self->state;
        self->f(v, self->state);
        self->switch_on.reset();
        self->switch_off.reset();
        self->switching = true;
        self->pos = 0;
    }

    float toggle::get_content_width() {
        return 60.0f;
    }

    float toggle::get_content_height() {
        return 40.0f;
    }

    void toggle::render() {
        glPushMatrix();

            glTranslatef(
                style.offset_x + style.margin_left,
                style.offset_y + style.margin_top,
                0.0f
            );
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            render_background();

            glPushMatrix();

                glTranslatef(
                    style.border_left.stroke + style.padding_left - 24.0f,
                    style.border_top.stroke + style.padding_top - 16.0f,
                    0.0f
                );

                if(switching) {
                    if(pos >= 5) {
                        if(state) {
                            frame_on->render();
                            circle_on->set_style(switch_on.tick(2));
                            circle_on->render();
                        } else {
                            frame_off->render();
                            circle_off->set_style(switch_off.tick(2));
                            circle_off->render();
                        }
                    } else {
                        if(state) {
                            frame_off->render();
                            circle_off->set_style(switch_on.tick(2));
                            circle_off->render();
                        } else {
                            frame_on->render();
                            circle_on->set_style(switch_off.tick(2));
                            circle_on->render();
                        }
                    }
                    pos += 2;
                    if(pos == 10) switching = false;
                } else {
                    if(state) {
                        frame_on->render();
                        circle_on->render();
                    } else {
                        frame_off->render();
                        circle_off->render();
                    }
                }

            glPopMatrix();

            render_borders();

        glPopMatrix();
    }

    toggle::toggle(std::function<void(view*, bool)> _f, bool checkmarks) : f(_f) {
        view::click_action = toggle_action;

        on_style.offset_x = 12;
        on_style.width = 108;
        on_style.height = 72;
        off_style.offset_x = -12;
        off_style.width = 108;
        off_style.height = 72;

        switch_on.start_value = off_style;
        switch_on.end_value = on_style;
        switch_off.end_value = off_style;
        switch_off.start_value = on_style;

        frame_off = symbols::toggle_frame()->size(72);
        frame_on = symbols::toggle_frame()->size(72);

        if(checkmarks) {
            circle_off = symbols::toggle_circle_cross()
                ->symbol_rendering_mode(symbol_rendering_modes::hierarchical)
                ->primary_color(color::accent_color);
            circle_on = symbols::toggle_circle_check()
                ->symbol_rendering_mode(symbol_rendering_modes::hierarchical);
        } else {
            circle_off = symbols::toggle_circle()
                ->symbol_rendering_mode(symbol_rendering_modes::hierarchical);
            circle_on = symbols::toggle_circle()
                ->symbol_rendering_mode(symbol_rendering_modes::hierarchical);
        }

        if(settings::is_dark_mode()) {
            frame_off->primary_color(color::dark_gray);
            frame_on->primary_color(color::accent_color);
            circle_off->primary_color(color::dark_gray);
        } else {
            frame_off->primary_color(color::gray);
            frame_on->primary_color(color::accent_color);
            circle_off->primary_color(color::gray);
        }

        circle_on->primary_color(color::accent_color);

        circle_off->set_style(off_style);
        circle_on->set_style(on_style);
    }

    void toggle::set_value(bool v) { if(v != state) toggle_action(this, 0.0f, 0.0f, nullptr); }

    toggle::~toggle() {
        if(frame_off) delete frame_off;
        if(frame_on) delete frame_on;
        if(circle_on) delete circle_on;
        if(circle_off) delete circle_off;
    }

}
