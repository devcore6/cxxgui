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

        std::function<void(view*, bool)> f;

        animation<10> switch_on;
        animation<10> switch_off;

        static void toggle_action(view* v, float x, float y, void* n);

    protected:

        float get_content_width();
        float get_content_height();

        void render();

    public:
        toggle(uint16_t weight, std::function<void(view*, bool)> _f);
        toggle(uint16_t weight, bool checkmarks, std::function<void(view*, bool)> _f);

        void set_value(bool v);

        ~toggle();

    };

    class picker : public view {

    };

    class slider : public view {

    };

    template<numeric_type T>
    class stepper : public view {
    private:

        symbol* s = nullptr;
        T value = 0;
        T min = 0;
        T max = 0;

        std::function<void(view*, T)> f;

        static void press_action(view* v, float x, float y, void* n) {
            stepper<T>* self = dynamic_cast<stepper<T>*>(v);

            if(x < 32.0f) {
                if(self->value > self->min || self->min == self->max)
                    self->value--;
            } else {
                if(self->value < self->max || self->min == self->max)
                    self->value++;
            }

            self->f(v, self->value);
        }

    protected:
        float get_content_width() { return 64.0f; }
        float get_content_height() { return 32.0f; }

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
                        case alignment_t::top_leading:      { h_alignment = 0; v_alignment = 0; break; }
                        case alignment_t::top:              { h_alignment = 1; v_alignment = 0; break; }
                        case alignment_t::top_trailing:     { h_alignment = 2; v_alignment = 0; break; }
                        case alignment_t::leading:          { h_alignment = 0; v_alignment = 1; break; }
                        case alignment_t::center:           { h_alignment = 1; v_alignment = 1; break; }
                        case alignment_t::trailing:         { h_alignment = 2; v_alignment = 1; break; }
                        case alignment_t::bottom_leading:   { h_alignment = 0; v_alignment = 2; break; }
                        case alignment_t::bottom:           { h_alignment = 1; v_alignment = 2; break; }
                        case alignment_t::bottom_trailing:  { h_alignment = 2; v_alignment = 2; break; }
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

                    if(h_alignment == 0) x_alignment_offset = 0;
                    if(h_alignment == 1) x_alignment_offset /= 2;

                    if(v_alignment == 0) y_alignment_offset = 0;
                    if(v_alignment == 1) y_alignment_offset /= 2;

                    glTranslatef(
                        -x_alignment_offset,
                        -y_alignment_offset,
                        0
                    );

                    s->render();

                    glPopMatrix();

                    if(h_alignment != 0 || v_alignment != 0) {
                        glPopMatrix();
                    }

                glPopMatrix();
                render_borders();

            glPopMatrix();
        }

    public:
        stepper(uint16_t weight, std::function<void(view*, T)> _f, T minv, T maxv, T start_value = 0) : f(_f), min(minv), max(maxv), value(start_value) {
            view::click_action = press_action;

            style.margin_bottom = 4;
            style.margin_top = 4;

            bool lighten_mid = false;

            switch(weight) {
                case 100: { s = symbols::stepper_thin();        break; }
                case 200: { s = symbols::stepper_extralight();  break; }
                case 300: { s = symbols::stepper_light();       break; }
                case 400: { s = symbols::stepper();             break; }
                case 500: { s = symbols::stepper_medium();      break; }
                case 600: { s = symbols::stepper_semibold();    break; }
                case 700: { s = symbols::stepper_bold();        break; }
                case 800: { s = symbols::stepper_extrabold();   break; }
                case 900: { s = symbols::stepper_black();       break; }
                default:  { s = symbols::stepper_fill(); lighten_mid = true; break; }
            }

            if(settings::is_dark_mode()) {
                s->primary_color(color::dark_gray);
                s->tertiary_color(lighten_mid ? color::gray : color::dark_gray);
            } else {
                s->primary_color(color::gray);
                s->tertiary_color(lighten_mid ? color::light_gray : color::gray);
            }

            s->size(64);
            s->symbol_rendering_mode(symbol_rendering_modes::palette);
        }

        void set_value(T v) { value = v; }

        ~stepper() { if(s) delete s; }

    };

    class date_picker : public view {

    };

    class color_picker : public view {

    };

    class textfield : public view {

    };

    class securefield : public view {

    };

    class texteditor : public view {

    };

}