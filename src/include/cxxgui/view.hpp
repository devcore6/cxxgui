#pragma once

namespace cxxgui {

    enum class stack_direction { vertical = 0, horizontal, depth };

    class view {
    public:
        style_t style;
        std::pair<std::vector<view*>, stack_direction> data;

        void render_borders();
        void render_background();

        virtual void init();
        virtual float get_content_width();
        virtual float get_content_height();
        virtual float get_content_box_width();
        virtual float get_content_box_height();
        virtual float get_width();
        virtual float get_height();
        virtual void render();
    };

    inline std::pair<std::vector<view*>, stack_direction> vstack(std::initializer_list<view*> data) {
        return { data, stack_direction::vertical };
    }

    inline std::pair<std::vector<view*>, stack_direction> hstack(std::initializer_list<view*> data) {
        return { data, stack_direction::horizontal };
    }

    inline std::pair<std::vector<view*>, stack_direction> zstack(std::initializer_list<view*> data) {
        return { data, stack_direction::depth };
    }

}
