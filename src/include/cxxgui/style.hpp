#pragma once

namespace cxxgui {

    enum class alignment_t {
           top_leading,  top,      top_trailing,
               leading, center,        trailing,
        bottom_leading, bottom, bottom_trailing
    };

    struct border_t {
        float stroke = 0.0f;
        uint32_t color = 0x00000000;
    };

    inline float pt(float px) { return px * 4.0f / 3.0f; }
    extern float em(float);
    extern float vw(float);
    extern float vh(float);

    inline SDL_Color uint32_t_to_sdl_color(uint32_t color) { return SDL_Color{
        static_cast<unsigned char>((color >> 24) & 0xFF),
        static_cast<unsigned char>((color >> 16) & 0xFF),
        static_cast<unsigned char>((color >> 8)  & 0xFF),
        static_cast<unsigned char>( color        & 0xFF)
    }; }

    struct style_t {

        float       offset_x                    = 0.0f;
        float       offset_y                    = 0.0f;

        float       margin_top                  = 0.0f;
        float       margin_right                = 0.0f;
        float       margin_left                 = 0.0f;
        float       margin_bottom               = 0.0f;

        float       padding_top                 = 0.0f;
        float       padding_right               = 0.0f;
        float       padding_left                = 0.0f;
        float       padding_bottom              = 0.0f;

        border_t    border_top                  = { 0.0f, 0xFFFFFFFF };
        border_t    border_right                = { 0.0f, 0xFFFFFFFF };
        border_t    border_left                 = { 0.0f, 0xFFFFFFFF };
        border_t    border_bottom               = { 0.0f, 0xFFFFFFFF };

        float       border_top_left_radius      = 0.0f;
        float       border_top_right_radius     = 0.0f;
        float       border_bottom_right_radius  = 0.0f;
        float       border_bottom_left_radius   = 0.0f;

        alignment_t alignment                   = alignment_t::center;

        uint32_t    background_color            = color::clear;
        uint32_t    color                       = color::foreground();

        float       width                       = 0.0f;
        float       height                      = 0.0f;

        float       min_width                   = 0.0f;
        float       max_width                   = 0.0f;
        float       min_height                  = 0.0f;
        float       max_height                  = 0.0f;

        float       rotation                    = 0.0f;

    };
}
