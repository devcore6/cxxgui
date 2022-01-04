#pragma once

namespace cxxgui {

    class view {
    protected:
        friend class window_t;
        friend class stack;

        view* parent = nullptr;

        std::function<void(view*, float, float, void*)> hover_action = nullptr;
        std::function<void(view*, float, float, void*)> leave_action = nullptr;
        std::function<void(view*, float, float, void*)> click_action = nullptr;
        void* hover_data = nullptr;
        void* leave_data = nullptr;
        void* click_data = nullptr;

        bool press_reset = true;
        bool was_hovering = false;

        // this is an awful solution, but I can't be bothered editing all the individual render functions right now
        // as such, it's fine and it'll do for now.
        // todo: change this later

        float __rel_x = 0;
        float __rel_y = 0;
        int __last_x = 0;
        int __last_y = 0;
        bool __clicking = false;
        bool __send_click = false;

        virtual float get_content_width();
        virtual float get_content_height();
        virtual float get_content_box_width();
        virtual float get_content_box_height();
        virtual float get_width();
        virtual float get_height();

        virtual bool hovering(float rel_x, float rel_y);

        virtual void render();
        void do_render(float rel_x, float rel_y, bool clicking, bool send_click, int lastx, int lasty);

        virtual view* clone() { return new view(*this); }

        void render_background();
        void render_borders();

        bool has_hover_style = false;
        bool has_active_style = false;

        style_t style;
        style_t hover_style;
        style_t active_style;

        style_t *rendered_style = &style;

        bool scrollbar_x = false;
        bool scrollbar_y = false;

    public:
        view* body = nullptr;

        virtual ~view() { if(body) delete body; }

        /*
         * Action executed on hover
         */
        view* on_hover(std::function<void(view*, float, float, void*)> callback, void* data = nullptr);

        /*
         * Action executed when leaving hover
         */
        view* on_leave(std::function<void(view*, float, float, void*)> callback, void* data = nullptr);

        /*
         * Action executed on click
         */
        view* on_click(std::function<void(view*, float, float, void*)> callback, void* data = nullptr);

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

        view* set_style(style_t new_style);

        view* align(alignment_t alignment);

        view* overflow(bool enable) { scrollbar_x = enable; scrollbar_y = enable; return this; }
        view* overflow(bool enable_y, bool enable_x) { scrollbar_x = enable_x; scrollbar_y = enable_y; return this; }

        /*
         * Layout on-hover
         */

        view* hover_offset(float x, float y);

        view* hover_margin(float margin);
        view* hover_margin(float vertical, float horizontal);
        view* hover_margin(float top, float right, float bottom, float left);

        view* hover_padding(float padding);
        view* hover_padding(float vertical, float horizontal);
        view* hover_padding(float top, float right, float bottom, float left);

        view* hover_border(border_t border);
        view* hover_border(border_t vertical, border_t horizontal);
        view* hover_border(border_t top, border_t right, border_t bottom, border_t left);

        view* hover_border_radius(float radius);
        view* hover_border_radius(float top_left, float top_right, float bottom_right, float bottom_left);

        view* hover_background_color(uint32_t color);
        view* hover_foreground_color(uint32_t color);

        view* hover_rotation(float degrees);

        /*
         * Layout on active (pressed)
         */

        view* active_offset(float x, float y);

        view* active_margin(float margin);
        view* active_margin(float vertical, float horizontal);
        view* active_margin(float top, float right, float bottom, float left);

        view* active_padding(float padding);
        view* active_padding(float vertical, float horizontal);
        view* active_padding(float top, float right, float bottom, float left);

        view* active_border(border_t border);
        view* active_border(border_t vertical, border_t horizontal);
        view* active_border(border_t top, border_t right, border_t bottom, border_t left);

        view* active_border_radius(float radius);
        view* active_border_radius(float top_left, float top_right, float bottom_right, float bottom_left);

        view* active_background_color(uint32_t color);
        view* active_foreground_color(uint32_t color);

        view* active_rotation(float degrees);

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

        float scrollbar_x_pos = 0.0f;
        float scrollbar_y_pos = 0.0f;

    public:
        void render();
        stack(std::initializer_list<view*> data) {
            for(auto v : data) v->parent = this;
            content = data;
        }
        ~stack() {
            for(auto v : content) if(v) { delete v; v = nullptr; }
        }
        void add(view* v) { content.push_back(v); }

    };

    class hstack : public stack {
    public:
        hstack(std::initializer_list<view*> data) : stack(data) {
            dir = stack_direction::horizontal;
        }
    };

    class vstack : public stack {
    public:
        vstack(std::initializer_list<view*> data) : stack(data) {
            dir = stack_direction::vertical;
        }
    };

    class zstack : public stack {
    public:
        zstack(std::initializer_list<view*> data) : stack(data) {
            dir = stack_direction::depth;
        }
    };
}
