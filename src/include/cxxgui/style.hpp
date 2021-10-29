#pragma once

namespace cxxgui {

    enum class align { left = 0, center, right, top, bottom };

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

        float                    margin_top                 = 0.0f,
                                 margin_right               = 0.0f,
                                 margin_left                = 0.0f,
                                 margin_bottom              = 0.0f;

        float                    padding_top                = 0.0f,
                                 padding_right              = 0.0f,
                                 padding_left               = 0.0f,
                                 padding_bottom             = 0.0f;

        float                    border_top                 = 0.0f,
                                 border_right               = 0.0f,
                                 border_left                = 0.0f,
                                 border_bottom              = 0.0f;

        uint32_t                 border_top_color           = 0xFFFFFFFF,
                                 border_right_color         = 0xFFFFFFFF,
                                 border_bottom_color        = 0xFFFFFFFF,
                                 border_left_color          = 0xFFFFFFFF;

        float                    border_top_left_radius     = 0.0f,
                                 border_top_right_radius    = 0.0f,
                                 border_bottom_right_radius = 0.0f,
                                 border_bottom_left_radius  = 0.0f;

        uint32_t                 font_size                  = 19;
        std::vector<std::string> font_family                = { };
        uint16_t                 font_weight                = 400;

        bool                     italic                     = false,
                                 underline                  = false,
                                 overline                   = false,
                                 strikethrough              = false;

        align                    vertical_align             = align::center,
                                 horizontal_align           = align::center;

        uint32_t                 color                      = 0xFFFFFFFF;
        uint32_t                 background_color           = 0x00000000;

        float                    translate_x                = 0.0f,
                                 translate_y                = 0.0f;

        float                    width                      = 0.0f,
                                 height                     = 0.0f;

        float                    min_width                  = 0.0f,
                                 max_width                  = 0.0f,
                                 min_height                 = 0.0f,
                                 max_height                 = 0.0f;

        float                    rotation                   = 0.0f;

    };
}
