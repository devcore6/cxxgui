#pragma once

namespace cxxgui {

    enum class symbol_rendering_modes { monochrome, hierarchical, palette };

    class symbol : public view {
    private:
        friend class toggle;

        std::string svg_data = "";
        GLuint texture_id = 0;

        uint32_t color1 = color::accent_color;
        uint32_t color2 = color::accent_color;
        uint32_t color3 = color::accent_color;
        uint32_t color4 = color::accent_color;
        uint32_t color5 = color::accent_color;

        uint16_t _weight = 16;

        float width = 0;
        float height = 0;

        symbol_rendering_modes render_mode = symbol_rendering_modes::monochrome;

    protected:
        float get_content_width();
        float get_content_height(); 
        
    public:
        void render();

        symbol() { }
        symbol(std::string data) : svg_data(data) { }
        ~symbol() { if(texture_id != 0) glDeleteTextures(1, &texture_id); }

        symbol* primary_color(uint32_t color) { color1 = color; return this; }
        symbol* secondary_color(uint32_t color) { color2 = color; return this; }
        symbol* tertiary_color(uint32_t color) { color3 = color; return this; }
        symbol* quarternary_color(uint32_t color) { color4 = color; return this; }
        symbol* quinary_color(uint32_t color) { color5 = color; return this; }
        
        symbol* weight(uint16_t w) { _weight = w; return this; }

        symbol* symbol_rendering_mode(symbol_rendering_modes mode) { render_mode = mode; return this; }

        symbol* size(float s) { style.width = s * 1.5f; style.height = s; return this; }

    };

}