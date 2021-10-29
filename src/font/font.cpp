#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    std::vector<font_t> fonts;

#ifdef __CXXGUI_LINUX
    std::filesystem::path system_fonts[3] = {
        std::filesystem::canonical("~/.fonts"),
        "/usr/local/share/fonts",
        "/usr/share/fonts"
    };
#endif

#ifdef __CXXGUI_MACOS
    std::filesystem::path system_fonts[3] = {
        std::filesystem::canonical("~/Library/Fonts"),
        "/Library/Fonts",
        "/System/Library/Fonts"
    };
#endif

#ifdef __CXXGUI_WINDOWS
    std::filesystem::path system_fonts[2] = {
            std::filesystem::temp_directory_path()  // %AppData%/../LocalLow/Temp
            .parent_path()                          // %AppData%/../LocalLow
            .parent_path()                          // %AppData%/..
            / "Local"                               // %AppData%/../Local
            / "Microsoft"                           // %AppData%/../Local/Microsoft
            / "Windows"                             // %AppData%/../Local/Microsoft/Windows
            / "Fonts",                              // %AppData%/../Local/Microsoft/Windows/Fonts
            "C:\\Windows\\Fonts"
    };
#endif

    font_t* try_load_font_from_path(std::string family, uint32_t size, uint16_t weight, std::string path) {
        font_t font = { nullptr, family, size, weight, path };

        font.font = TTF_OpenFont(std::filesystem::canonical(path).string().c_str(), size);

        if(!font.font) return nullptr;

        fonts.push_back(font);

        return &fonts[fonts.size() - 1];
    }

    font_t* try_load_font(std::string family, uint32_t size, uint16_t weight) {
        for(auto path : system_fonts) {
            font_t* font = try_load_font_from_path(family, size, weight, (path / (family + ".ttf")).string());
            if(font != nullptr) return font;
        }

        return nullptr;
    }

    font_t* try_register_font_path(std::string family, uint16_t weight, std::string path) {
        return try_load_font_from_path(family, 12, weight, path);
    }

}
