#pragma once

namespace cxxgui {
    struct font_family_t {
        std::string name = "";
        std::string mono_name = "";
        std::string paths[36] = { "" }; // [ 0] .. [ 8] - weight = 100 .. 900, italic = false, monospace = false
                                        // [ 9] .. [17] - weight = 100 .. 900, italic = true,  monospace = false
                                        // [18] .. [26] - weight = 100 .. 900, italic = false, monospace = true
                                        // [27] .. [35] - weight = 100 .. 900, italic = true,  monospace = true
    };

    extern font_family_t system;

    class font_t {
    protected:
        friend class text;

        TTF_Font* font = nullptr;
        font_family_t* family = nullptr;
        const uint32_t size = 12;
        const uint16_t weight = 400;
        const bool italic = false;
        const bool monospaced = false;

    public:
        font_t(font_family_t* f, uint32_t s, uint16_t w, bool i, bool m) : family(f), size(s), weight(w), italic(i), monospaced(m) { }
        // ~font_t() { if(font) TTF_CloseFont(font); }

        font_t* toggle_italic();
        font_t* set_size(uint32_t s);
        font_t* set_weight(uint16_t w);

        static font_t* try_load_font(font_family_t* family, uint32_t size, uint16_t weight, bool italic, bool monospaced);
        static font_t* try_load_font_from_path(font_family_t* family, uint32_t size, uint16_t weight, bool italic, bool monospaced, std::string path);
    };

    extern std::vector<font_t*> fonts;

    extern font_t* large_title;
    extern font_t* title;
    extern font_t* headline;
    extern font_t* subheadline;
    extern font_t* body;
    extern font_t* caption;
    extern font_t* footnote;
    extern font_t* monospace;
}
