#pragma once

namespace cxxgui {

    enum class symbol_rendering_modes { monochrome, palette };

    class symbol : public view {
    private:
        std::string svg_data = "";
        GLuint texture_id = 0;

        uint32_t color1 = color::accent_color;
        uint32_t color2 = color::accent_color;
        uint32_t color3 = color::accent_color;
        uint32_t color4 = color::accent_color;

        float width = 0;
        float height = 0;

        symbol_rendering_modes render_mode = symbol_rendering_modes::monochrome;

    protected:
        float get_content_width();
        float get_content_height();
        void render();

    public:
        symbol() { }
        symbol(std::string data) : svg_data(data) { }

        symbol* primary_color(uint32_t color) { color1 = color; return this; }
        symbol* secondary_color(uint32_t color) { color2 = color; return this; }
        symbol* tertiary_color(uint32_t color) { color3 = color; return this; }
        symbol* quarternary_color(uint32_t color) { color4 = color; return this; }

        symbol* symbol_rendering_mode(symbol_rendering_modes mode) { render_mode = mode; return this; }

        symbol* size(float s) { style.width = s; style.height = s; return this; }

    };

}