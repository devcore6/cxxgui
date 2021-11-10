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

        static void toggle_action(view* v, void* n);

    protected:

        float get_content_width();
        float get_content_height();

        void render();

    public:
        toggle(uint16_t weight, std::function<void(bool)> _f);
        toggle(uint16_t weight, bool checkmarks, std::function<void(bool)> _f);

        void set_value(bool v);

        ~toggle();

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