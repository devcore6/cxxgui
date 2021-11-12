#pragma once

namespace cxxgui {
    class text : public view {
    private:
        friend class font_t;

        std::string t = "";
        font_t* internal_font = nullptr;
        GLuint texture_id = 0;
        float width = 0;
        float height = 0;

    protected:
        float get_content_width();
        float get_content_height();
        void render();

    public:
        text(const char* str) : t(str) { internal_font = cxxgui::body; }
        text(std::string str) : t(str) { internal_font = cxxgui::body; }
        text(const char* str, font_t* f) : t(str), internal_font(f) { }
        text(std::string str, font_t* f) : t(str), internal_font(f) {}
        ~text() { if(texture_id != 0) glDeleteTextures(1, &texture_id); }

        /*
         * Update text
         */

        text* set_text(const char* str);

        /*
         * Layout
         */

        text* font(font_t* f);
        text* toggle_italic();
        text* font_size(uint32_t s);
        text* font_weight(uint16_t w);

        /*
         * Concatenation
         */
        
        text* operator+=(text* rhs);

        /*
         * Comparison
         */

        bool operator==(text* rhs);
        bool operator!=(text* rhs);
    };
}
