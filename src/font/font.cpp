#include <string>
#include <vector>
#include <filesystem>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include <cxxgui/font.hpp>

namespace cxxgui {

#if defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
    std::filesystem::path system_fonts[4] = {
        std::filesystem::canonical("~/.fonts"),
        "/usr/local/share/fonts",
        "/usr/share/fonts",
        "/usr/local/share/truetype"
};
#elif defined(__APPLE__) && defined(__MACH__)
    std::filesystem::path system_fonts[3] = {
        std::filesystem::canonical("~/Library/Fonts"),
        "/Library/Fonts",
        "/System/Library/Fonts"
    };
#elif defined(_WIN32) || defined(_WIN64)
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

    std::vector<font_t*> fonts;

    /*
     * This is kinda disgusting and I absolutely love it. Not gonna change it.
     */
    bool cleanup_fonts = []() -> bool { atexit([]() { for(font_t* f : fonts) if(f) { delete f; f = nullptr; } }); return true; }();

    uint16_t font_weight_to_id(uint16_t weight, bool italic, bool monospaced) {
        return weight / 100 + (italic ? 8 : -1) + (monospaced ? 18 : 0);
    }

    font_t* font_t::toggle_italic() {
        return try_load_font(family, size, weight, !italic, monospaced);
    }

    font_t* font_t::set_size(uint32_t s) {
        return try_load_font(family, s, weight, italic, monospaced);
    }

    font_t* font_t::set_weight(uint16_t w) {
        return try_load_font(family, size, w, italic, monospaced);
    }

    font_t* font_t::try_load_font(font_family_t* family, uint32_t size, uint16_t weight, bool italic, bool monospaced) {
        font_t* font = new font_t(family, size, weight, italic, monospaced);
        
        font->font = TTF_OpenFont(
            std::filesystem::canonical(
                family->paths[font_weight_to_id(weight, italic, monospaced)]
            ).string().c_str(), size
        );

        if(!font->font) { delete font; return nullptr; }

        fonts.push_back(font);
        return fonts[fonts.size() - 1];
    }

    font_t* font_t::try_load_font_from_path(font_family_t *family, uint32_t size, uint16_t weight, bool italic, bool monospaced, std::string path) {
        font_t* font = new font_t(family, size, weight, italic, monospaced);
        font->font = TTF_OpenFont(std::filesystem::canonical(path).string().c_str(), size);

        if(!font->font) { delete font; return nullptr; }

        fonts.push_back(font);
        family->paths[font_weight_to_id(weight, italic, monospaced)] = path;
        return fonts[fonts.size() - 1];
    }

    bool try_load_system_font(font_family_t* family, uint16_t weight, bool monospaced, bool italic) {
        for(auto path : system_fonts) {
            std::string p = (path / family->paths[font_weight_to_id(weight, italic, monospaced)]).string();
            TTF_Font *font = TTF_OpenFont(p.c_str(), 16);

            if(!font) continue;

            TTF_CloseFont(font);
            family->paths[font_weight_to_id(weight, italic, monospaced)] = p;
            return true;
        }
        return false;
    }

    font_family_t system = []() -> font_family_t {
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) exit(EXIT_FAILURE);
        atexit(SDL_Quit);

        if(TTF_Init() < 0) exit(EXIT_FAILURE);
        atexit(TTF_Quit);

        if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP) < 0) exit(EXIT_FAILURE);
        atexit(IMG_Quit);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        /*
         * Try SF Pro Text (macOS, iOS, iPadOS, watchOS system font) as primary font
         */

        font_family_t ret = {
            "SF Pro Text",
            "SF Mono",
            {
                "SF-Pro-Text-UltraLight.otf",
                "SF-Pro-Text-Thin.otf",
                "SF-Pro-Text-Light.otf",
                "SF-Pro-Text-Regular.otf",
                "SF-Pro-Text-Medium.otf",
                "SF-Pro-Text-Semibold.otf",
                "SF-Pro-Text-Bold.otf",
                "SF-Pro-Text-Heavy.otf",
                "SF-Pro-Text-Black.otf",

                "SF-Pro-Text-ThinItalic.otf",
                "SF-Pro-Text-UltralightItalic.otf",
                "SF-Pro-Text-LightItalic.otf",
                "SF-Pro-Text-RegularItalic.otf",
                "SF-Pro-Text-MediumItalic.otf",
                "SF-Pro-Text-SemiboldItalic.otf",
                "SF-Pro-Text-BoldItalic.otf",
                "SF-Pro-Text-HeavyItalic.otf",
                "SF-Pro-Text-BlackItalic.otf",

                "SF-Mono-Light.otf",            // Thin doesn't exist, use light
                "SF-Mono-Light.otf",            // Ultra light doesn't exist, use light
                "SF-Mono-Light.otf",
                "SF-Mono-Regular.otf",
                "SF-Mono-Medium.otf",
                "SF-Mono-Semibold.otf",
                "SF-Mono-Bold.otf",
                "SF-Mono-Heavy.otf",
                "SF-Mono-Heavy.otf",            // Black doesn't exist, use heavy

                "SF-Mono-LightItalic.otf",      // Thin doesn't exist, use light
                "SF-Mono-LightItalic.otf",      // Ultra light doesn't exist, use light
                "SF-Mono-LightItalic.otf",
                "SF-Mono-RegularItalic.otf",
                "SF-Mono-MediumItalic.otf",
                "SF-Mono-SemiboldItalic.otf",
                "SF-Mono-BoldItalic.otf",
                "SF-Mono-HeavyItalic.otf",
                "SF-Mono-HeavyItalic.otf"       // Black doesn't exist, use heavy
            }
        };

        bool found = true;
        for(uint16_t i = 0; i < 9; i++) {
            if(!try_load_system_font(&ret, (i + 1) * 100, false, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, false, true)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, true)) { found = false; break; }
        }
        if(found) return ret;

        /*
         * If SF Pro Text wasn't found, try Segoe UI (Windows system font)
         */

        ret = {
            "Segoe UI",
            "Consolas",
            {
                "segoeuil.ttf",             // Thin doesn't exist, use light
                "segoeuil.ttf",             // Ultra light doesn't exist, use light
                "segoeuisl.ttf",            // SegoeUI has a non-standard 350weight semi-light variant, we'll use that as the light variant
                "segoeui.ttf",
                "seguisb.ttf",              // Medium doesn't exist, use semibold
                "seguisb.ttf",
                "segoeuib.ttf",
                "seguibl.ttf",              // Heavy doesn't exist, use black
                "seguibl.ttf",

                "seguili.ttf",              // Thin doesn't exist, use light
                "seguili.ttf",              // Extra light doesn't exist, use light
                "seguisli.ttf",             // SegoeUI has a non-standard 350weight semi-light variant, we'll use that as the light variant
                "segoeuii.ttf",
                "seguisbi.ttf",             // Medium doesn't exist, use semibold
                "seguisbi.ttf",
                "segoeuiz.ttf",
                "seguibli.ttf",             // Heavy doesn't exist, use black
                "seguibli.ttf",

                "consola.ttf",             // Thin doesn't exist, use regular
                "consola.ttf",             // Ultra light doesn't exist, use regular
                "consola.ttf",             // Light doesn't exist, use regular
                "consola.ttf",
                "consola.ttf",             // Medium doesn't exist, use regular
                "consolab.ttf",            // Semibold doesn't exist, use bold
                "consolab.ttf",
                "consolab.ttf",            // Heavy doesn't exist, use bold
                "consolab.ttf",            // Black doesn't exist, use bold

                                            // Consolas doesn't have italic fonts, use normal fonts

                "consolai.ttf",            // Thin doesn't exist, use regular
                "consolai.ttf",            // Ultra light doesn't exist, use regular
                "consolai.ttf",            // Light doesn't exist, use regular
                "consolai.ttf",
                "consolai.ttf",            // Medium doesn't exist, use regular
                "consolaz.ttf",            // Semibold doesn't exist, use bold
                "consolaz.ttf",
                "consolaz.ttf",            // Heavy doesn't exist, use bold
                "consolaz.ttf",            // Black doesn't exist, use bold
            }
        };

        found = true;
        for(uint16_t i = 0; i < 9; i++) {
            if(!try_load_system_font(&ret, (i + 1) * 100, false, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, false, true)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, true)) { found = false; break; }
        }
        if(found) return ret;

        /*
         * Ahh, Linux. This is where we get in trouble, since Linux doesn't have a default font and every distro has its own fonts.
         * As such, I'll use DejaVu Sans as it's the default font on Ubuntu.
         */

        ret = {
            "DejaVu Sans",
            "DejaVu Sans Mono",
            {
                "DejaVuSans.ttf",           // Thin doesn't exist, use regular
                "DejaVuSans.ttf",           // Ultra light doesn't exist, use regular
                "DejaVuSans.ttf",           // Light doesn't exist, use regular
                "DejaVuSans.ttf",
                "DejaVuSans.ttf",           // Medium doesn't exist, use regular
                "DejaVuSans-Bold.ttf",      // Semibold doesn't exist, use bold
                "DejaVuSans-Bold.ttf",
                "DejaVuSans-Bold.ttf",      // Heavy doesn't exist, use bold
                "DejaVuSans-Bold.ttf",      // Black doesn't exist, use bold

                                            // DejaVu Sans doesn't have italic fonts, use normal fonts

                "DejaVuSans.ttf",           // Thin doesn't exist, use regular
                "DejaVuSans.ttf",           // Ultra light doesn't exist, use regular
                "DejaVuSans.ttf",           // Light doesn't exist, use regular
                "DejaVuSans.ttf",
                "DejaVuSans.ttf",           // Medium doesn't exist, use regular
                "DejaVuSans-Bold.ttf",      // Semibold doesn't exist, use bold
                "DejaVuSans-Bold.ttf",
                "DejaVuSans-Bold.ttf",      // Heavy doesn't exist, use bold
                "DejaVuSans-Bold.ttf",      // Black doesn't exist, use bold

                "DejaVuSansMono.ttf",       // Thin doesn't exist, use regular
                "DejaVuSansMono.ttf",       // Ultra light doesn't exist, use regular
                "DejaVuSansMono.ttf",       // Light doesn't exist, use regular
                "DejaVuSansMono.ttf",
                "DejaVuSansMono.ttf",       // Medium doesn't exist, use regular
                "DejaVuSansMono-Bold.ttf",  // Semibold doesn't exist, use bold
                "DejaVuSansMono-Bold.ttf",
                "DejaVuSansMono-Bold.ttf",  // Heavy doesn't exist, use bold
                "DejaVuSansMono-Bold.ttf",  // Black doesn't exist, use bold

                                            // DejaVu Sans Mono doesn't have italic fonts, use normal fonts

                "DejaVuSansMono.ttf",       // Thin doesn't exist, use regular
                "DejaVuSansMono.ttf",       // Ultra light doesn't exist, use regular
                "DejaVuSansMono.ttf",       // Light doesn't exist, use regular
                "DejaVuSansMono.ttf",
                "DejaVuSansMono.ttf",       // Medium doesn't exist, use regular
                "DejaVuSansMono-Bold.ttf",  // Semibold doesn't exist, use bold
                "DejaVuSansMono-Bold.ttf",
                "DejaVuSansMono-Bold.ttf",  // Heavy doesn't exist, use bold
                "DejaVuSansMono-Bold.ttf"   // Black doesn't exist, use bold
            }
        };

        found = true;
        for(uint16_t i = 0; i < 9; i++) {
            if(!try_load_system_font(&ret, (i + 1) * 100, false, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, false)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, false, true)) { found = false; break; }
            if(!try_load_system_font(&ret, (i + 1) * 100, true, true)) { found = false; break; }
        }
        if(found) return ret;

        return { "", { "" } };
    }();
    
    font_t* large_title = font_t::try_load_font(&system, 40, 700, false, false);
    font_t* title       = font_t::try_load_font(&system, 32, 600, false, false);
    font_t* headline    = font_t::try_load_font(&system, 16, 600, false, false);
    font_t* subheadline = font_t::try_load_font(&system, 15, 400, false, false);
    font_t* body        = font_t::try_load_font(&system, 16, 400, false, false);
    font_t* footnote    = font_t::try_load_font(&system, 14, 400, false, false);
    font_t* monospace   = font_t::try_load_font(&system, 16, 400, false, true);

}
