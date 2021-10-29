#pragma once

namespace cxxgui {
    class text : public view {
    private:
        std::string t = "";
        std::vector<font_t*> cur_fonts;
        bool has_font = true;
        GLuint texture_id = 0;
        size_t width = 0;
        size_t height = 0;

    public:
        text(const char* str) : t(str) { }

        text(const char* str, const char* font_family, uint32_t font_size, uint16_t font_weight, bool italic = false) : t(str) {
            style.font_family.push_back(font_family);
            style.font_size = font_size;
            style.font_weight = font_weight;
            style.italic = italic;
        }

        void init();
        float get_content_width();
        float get_content_height();
        void render();
    };
}
