#pragma once

namespace cxxgui {

    class view {
    protected:
        friend class window_t;
        friend class stack;

        virtual float get_content_width();
        virtual float get_content_height();
        virtual float get_content_box_width();
        virtual float get_content_box_height();
        virtual float get_width();
        virtual float get_height();

        virtual void render();

        virtual view* clone() { return new view(*this); }

        void render_background();
        void render_borders();

        style_t style;

    public:
        view* body = nullptr;

        /*
         * Layout
         */

        view* frame(float min_w, float ideal_w, float max_w,
                    float min_h, float ideal_h, float max_h,
                    alignment_t alignment);

        view* offset(float x, float y);

        view* margin(float margin);
        view* margin(float vertical, float horizontal);
        view* margin(float top, float right, float bottom, float left);

        view* padding(float padding);
        view* padding(float vertical, float horizontal);
        view* padding(float top, float right, float bottom, float left);

        view* border(border_t border);
        view* border(border_t vertical, border_t horizontal);
        view* border(border_t top, border_t right, border_t bottom, border_t left);

        view* border_radius(float radius);
        view* border_radius(float top_left, float top_right, float bottom_right, float bottom_left);

        view* background_color(uint32_t color);
        view* foreground_color(uint32_t color);

        view* rotation(float degrees);

    };

    /*
     * View stacks
     */

    class stack : public view {
    protected:
        friend class view;

        enum class stack_direction { horizontal, vertical, depth };
        stack_direction dir;

        std::vector<view*> content;

        float get_content_width();
        float get_content_height();

    public:
        void render();

    };

    class hstack : public stack {
    public:
        hstack(std::initializer_list<view*> data) {
            dir = stack_direction::horizontal;
            content = data;
        }
    };

    class vstack : public stack {
    public:
        vstack(std::initializer_list<view*> data) {
            dir = stack_direction::vertical;
            content = data;
        }
    };

    class zstack : public stack {
    public:
        zstack(std::initializer_list<view*> data) {
            dir = stack_direction::depth;
            content = data;
        }
    };
}
