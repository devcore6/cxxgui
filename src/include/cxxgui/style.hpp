#pragma once

namespace cxxgui {

    enum class align { left = 0, center, right, top, bottom };

    inline GLfloat pt(GLfloat px) { return px * 4.0f / 3.0f; }
    extern GLfloat em(GLfloat);
    extern GLfloat vw(GLfloat);
    extern GLfloat vh(GLfloat);

    struct style_t {

        GLfloat                  margin_top                 = 0.0f,
                                 margin_right               = 0.0f,
                                 margin_left                = 0.0f,
                                 margin_bottom              = 0.0f;

        GLfloat                  padding_top                = 0.0f,
                                 padding_right              = 0.0f,
                                 padding_left               = 0.0f,
                                 padding_bottom             = 0.0f;

        GLfloat                  border_top                 = 0.0f,
                                 border_right               = 0.0f,
                                 border_left                = 0.0f,
                                 border_bottom              = 0.0f;

        uint32_t                 border_top_color           = 0xFFFFFFFF,
                                 border_right_color         = 0xFFFFFFFF,
                                 border_bottom_color        = 0xFFFFFFFF,
                                 border_left_color          = 0xFFFFFFFF;

        GLfloat                  border_top_left_radius     = 0.0f,
                                 border_top_right_radius    = 0.0f,
                                 border_bottom_right_radius = 0.0f,
                                 border_bottom_left_radius  = 0.0f;

        GLfloat                  font_size                  = 19.0f;
        std::vector<std::string> font_family                = { };
        uint16_t                 font_weight                = 400;

        bool                     italic                     = false,
                                 underline                  = false,
                                 overline                   = false,
                                 strikethrough              = false;

        align                    vertical_align             = align::top,
                                 horizontal_align           = align::left;

        uint32_t                 color                      = 0xFFFFFFFF;
        uint32_t                 background_color           = 0x00000000;

        GLfloat                  translate_x                = 0.0f,
                                 translate_y                = 0.0f;

        GLfloat                  width                      = 0.0f,
                                 height                     = 0.0f;

        GLfloat                  min_width                  = 0.0f,
                                 max_width                  = 0.0f,
                                 min_height                 = 0.0f,
                                 max_height                 = 0.0f;

        GLfloat                  rotation                   = 0.0f;

    };
}
