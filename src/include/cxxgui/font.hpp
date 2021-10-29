#pragma once

namespace cxxgui {
    struct font_t {
        TTF_Font* font = nullptr;
        std::string family = "";
        uint32_t size = 12;
        uint16_t weight = 400;
        bool italic = false;
        std::string path = "";
    };

    extern std::vector<font_t> fonts;

    extern font_t* try_load_font_from_path(std::string family, uint32_t size, uint16_t weight, bool italic, std::string path);
    extern font_t* try_load_font(std::string family, uint32_t size, uint16_t weight, bool italic);
    extern font_t* try_register_font_path(std::string family, uint16_t weight, bool italic, std::string path);
}
