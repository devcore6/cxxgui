#pragma once

namespace cxxgui {

    class toggle : public view {
    private:
        friend class symbol;

        symbol* frame_off = nullptr;
        symbol* frame_on = nullptr;

        symbol* circle_on = nullptr;
        symbol* circle_off = nullptr;

        bool checkmarks = true;
        bool state = false;
        bool switching = false;

        size_t pos = 0;

        style_t on_style;
        style_t off_style;

        std::function<void(bool)> f;

        animation<10> switch_on;
        animation<10> switch_off;

        static void toggle_action(view* v, void* n) {
            toggle* self = dynamic_cast<toggle*>(v);
            self->state = !self->state;
            self->f(self->state);
            self->switch_on.reset();
            self->switch_off.reset();
            self->switching = true;
            self->pos = 0;
        }

    protected:

        float get_content_width() {
            return 64.0f;
        }

        float get_content_height() {
            return 64.0f;
        }

        void render() {
            glPushMatrix();

                glTranslatef(style.offset_x + style.margin_left,
                             style.offset_y + style.margin_top,
                             0.0f);
                glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

                float w = get_content_box_width();
                float h = get_content_box_height();

                render_background();
                glPushMatrix();

                    glTranslatef(style.border_left.stroke + style.padding_left,
                                 style.border_top.stroke + style.padding_top,
                                 0.0f);

                    int h_alignment = 0;
                    int v_alignment = 0;

                    switch(style.alignment) {
                        case alignment_t::top_leading:     { h_alignment = 0; v_alignment = 0; break; }
                        case alignment_t::top:             { h_alignment = 1; v_alignment = 0; break; }
                        case alignment_t::top_trailing:    { h_alignment = 2; v_alignment = 0; break; }
                        case alignment_t::leading:         { h_alignment = 0; v_alignment = 1; break; }
                        case alignment_t::center:          { h_alignment = 1; v_alignment = 1; break; }
                        case alignment_t::trailing:        { h_alignment = 2; v_alignment = 1; break; }
                        case alignment_t::bottom_leading:  { h_alignment = 0; v_alignment = 2; break; }
                        case alignment_t::bottom:          { h_alignment = 1; v_alignment = 2; break; }
                        case alignment_t::bottom_trailing: { h_alignment = 2; v_alignment = 2; break; }
                    }

                    if(h_alignment != 0 || v_alignment != 0) {
                        glPushMatrix();

                            glTranslatef(
                                (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w),
                                (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h),
                                0.0f
                            );
                    }

                    float x_alignment_offset = 64.0f + style.padding_left + style.padding_right,
                          y_alignment_offset = 64.0f + style.padding_top + style.padding_bottom;

                    glPushMatrix();

                        if(h_alignment == 0) x_alignment_offset  = 0;
                        if(h_alignment == 1) x_alignment_offset /= 2;
                        
                        if(v_alignment == 0) y_alignment_offset  = 0;
                        if(v_alignment == 1) y_alignment_offset /= 2;

                        glTranslatef(
                            -x_alignment_offset,
                            -y_alignment_offset,
                            0
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

                    if(h_alignment != 0 || v_alignment != 0) {
                        glPopMatrix();
                    }

                glPopMatrix();
                render_borders();

            glPopMatrix();
        }

    public:
        toggle(uint16_t weight, std::function<void(bool)> _f) : f(_f) {
            view::click_action = toggle_action;

            on_style.offset_x = 16;
            on_style.width = 64;
            on_style.height = 64;
            off_style.offset_x = -16;
            off_style.width = 64;
            off_style.height = 64;

            switch_on.start_value = off_style;
            switch_on.end_value = on_style;
            switch_off.end_value = off_style;
            switch_off.start_value = on_style;

            switch(weight) {
                case 100: {
                    frame_off = symbols::toggle_frame_thin();
                    frame_on = symbols::toggle_frame_thin();
                    break;
                }
                case 200: {
                    frame_off = symbols::toggle_frame_extralight();
                    frame_on = symbols::toggle_frame_extralight();
                    break;
                }
                case 300: {
                    frame_off = symbols::toggle_frame_light();
                    frame_on = symbols::toggle_frame_light();
                    break;
                }
                case 400: {
                    frame_off = symbols::toggle_frame();
                    frame_on = symbols::toggle_frame();
                    break;
                }
                case 500: {
                    frame_off = symbols::toggle_frame_medium();
                    frame_on = symbols::toggle_frame_medium();
                    break;
                }
                case 600: {
                    frame_off = symbols::toggle_frame_semibold();
                    frame_on = symbols::toggle_frame_semibold();
                    break;
                }
                case 700: {
                    frame_off = symbols::toggle_frame_bold();
                    frame_on = symbols::toggle_frame_bold();
                    break;
                }
                case 800: {
                    frame_off = symbols::toggle_frame_extrabold();
                    frame_on = symbols::toggle_frame_extrabold();
                    break;
                }
                case 900: {
                    frame_off = symbols::toggle_frame_black();
                    frame_on = symbols::toggle_frame_black();
                    break;
                }
                default: {
                    frame_off = symbols::toggle_frame_fill();
                    frame_on = symbols::toggle_frame_fill();
                    break;
                }
            }

            circle_off = symbols::toggle_circle_fill();
            circle_on = symbols::toggle_circle_fill();

            if(settings::is_dark_mode()) {
                frame_off->primary_color(color::dark_gray);
                frame_on->primary_color(color::accent_color);
                circle_off->primary_color(color::light_gray);
                circle_on->primary_color(color::light_gray);
            } else {
                frame_off->primary_color(color::gray);
                frame_on->primary_color(color::accent_color);
                circle_off->primary_color(color::white);
                circle_on->primary_color(color::white);
            }

            frame_off->size(64);
            frame_on->size(64);
            circle_off->size(64)->set_style(off_style);
            circle_on->size(64)->set_style(on_style);
        }

        toggle(uint16_t weight, bool checkmarks, std::function<void(bool)> _f) : f(_f) {
            view::click_action = toggle_action;

            on_style.offset_x = 16;
            on_style.width = 64;
            on_style.height = 64;
            off_style.offset_x = -16;
            off_style.width = 64;
            off_style.height = 64;

            switch_on.start_value = off_style;
            switch_on.end_value = on_style;
            switch_off.end_value = off_style;
            switch_off.start_value = on_style;

            switch(weight) {
                case 100: {
                    frame_off = symbols::toggle_frame_thin();
                    frame_on = symbols::toggle_frame_thin();
                    break;
                }
                case 200: {
                    frame_off = symbols::toggle_frame_extralight();
                    frame_on = symbols::toggle_frame_extralight();
                    break;
                }
                case 300: {
                    frame_off = symbols::toggle_frame_light();
                    frame_on = symbols::toggle_frame_light();
                    break;
                }
                case 400: {
                    frame_off = symbols::toggle_frame();
                    frame_on = symbols::toggle_frame();
                    break;
                }
                case 500: {
                    frame_off = symbols::toggle_frame_medium();
                    frame_on = symbols::toggle_frame_medium();
                    break;
                }
                case 600: {
                    frame_off = symbols::toggle_frame_semibold();
                    frame_on = symbols::toggle_frame_semibold();
                    break;
                }
                case 700: {
                    frame_off = symbols::toggle_frame_bold();
                    frame_on = symbols::toggle_frame_bold();
                    break;
                }
                case 800: {
                    frame_off = symbols::toggle_frame_extrabold();
                    frame_on = symbols::toggle_frame_extrabold();
                    break;
                }
                case 900: {
                    frame_off = symbols::toggle_frame_black();
                    frame_on = symbols::toggle_frame_black();
                    break;
                }
                default: {
                    frame_off = symbols::toggle_frame_fill();
                    frame_on = symbols::toggle_frame_fill();
                    break;
                }
            }

            if(checkmarks) {
                circle_off = symbols::toggle_circle_cross_fill()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette);
                circle_on = symbols::toggle_circle_checkmark_fill()
                    ->symbol_rendering_mode(symbol_rendering_modes::palette);
            } else {
                circle_off = symbols::toggle_circle_fill();
                circle_on = symbols::toggle_circle_fill();
            }

            if(settings::is_dark_mode()) {
                frame_off->primary_color(color::dark_gray);
                frame_on->primary_color(color::accent_color);
                circle_off->primary_color(color::light_gray)->secondary_color(color::dark_gray);
                circle_on->primary_color(color::light_gray);
            } else {
                frame_off->primary_color(color::gray);
                frame_on->primary_color(color::accent_color);
                circle_off->primary_color(color::white)->secondary_color(color::gray);
                circle_on->primary_color(color::white);
            }

            frame_off->size(64);
            frame_on->size(64);
            circle_off->size(64)->set_style(off_style);
            circle_on->size(64)->set_style(on_style);
        }

        void set_value(bool v) { if(v != state) toggle_action(this, nullptr); }

        ~toggle() {
            if(frame_off) delete frame_off;
            if(frame_on) delete frame_on;
            if(circle_on) delete circle_on;
            if(circle_off) delete circle_off;
        }

    };

    class picker : public view {

    };

    class slider : public view {

    };

    class stepper : public view {

    };

    class date_picker : public view {

    };

    class color_picker : public view {

    };

}