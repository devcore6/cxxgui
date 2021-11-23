#pragma once
namespace cxxgui {
#ifdef __CXXGUI_DESKTOP__
    struct shortcut_t {
        // temporary stub
    };

    struct menubar_entry;

    struct menubar_target {
        enum class val_t { menubar, view };
        val_t val;

        union {
            menubar_entry* mb;
            view* v;
        } value;
    };

    struct menubar_entry {
        const char* text = nullptr;
        std::optional<shortcut_t> shortcut;
        menubar_target action;
    };
#endif

    struct app {
        std::string title;
        view* body = nullptr;

        // Only for desktop
        std::vector<menubar_entry> menubar;
        size_t width = 1280;
        size_t height = 720;
        uint16_t refresh_rate = 60;

        void main();
        ~app();
    };
}
