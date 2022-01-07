#pragma once

namespace cxxgui {

    class toggle : public view {
    private:
        friend class symbol;
        friend class var_toggle;

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
        toggle(std::function<void(view*, bool)> _f, bool checkmarks = false);

        void set_value(bool v);
        void toggle_value();
        bool get_value();

        ~toggle();

    };

    inline toggle* var_toggle(bool* var, bool checkmarks = false) {
        toggle* tog = new toggle([var](view*, bool v) {
            *var = v;
        }, checkmarks);
        if(*var) tog->toggle_value();
        return tog;
    }

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

            if(x < 30.0f) {
                if(self->value > self->min || self->min == self->max)
                    self->value--;
            } else {
                if(self->value < self->max || self->min == self->max)
                    self->value++;
            }

            if(self->f != nullptr) self->f(v, self->value);
        }

    protected:
        float get_content_width() { return 60.0f; }
        float get_content_height() { return 40.0f; }

        void render() {
            glPushMatrix();

                glTranslatef(style.offset_x + style.margin_left,
                             style.offset_y + style.margin_top,
                             0.0f);
                glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

                render_background();

                glPushMatrix();

                    glTranslatef(style.border_left.stroke + style.padding_left - 24.0f,
                                 style.border_top.stroke + style.padding_top - 16.0f,
                                 0.0f);

                    s->render();

                glPopMatrix();

                render_borders();

            glPopMatrix();
        }

    public:
        stepper(std::function<void(view*, T)> _f, T minv, T maxv, T start_value = 0) : f(_f), min(minv), max(maxv), value(start_value) {
            view::click_action = press_action;

            s = symbols::stepper();

            if(settings::is_dark_mode())
                s->primary_color(color::dark_gray)->symbol_rendering_mode(symbol_rendering_modes::hierarchical)->size(72);
            else
                s->primary_color(color::gray)->symbol_rendering_mode(symbol_rendering_modes::hierarchical)->size(72);
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
