#pragma once
namespace cxxgui {
#ifdef __CXXGUI_DESKTOP__
    class window_t;

    extern bool null_function(window_t*, void*);
    extern void null_handler(SDL_Event e);

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
        std::function<void(SDL_Event)> event_handler = null_handler;
        uint16_t refresh_rate = 60;
        float opacity = 1.0f;
        std::function<bool(window_t*, void*)> main_loop = null_function;
        std::function<bool(window_t*, void*)> post_loop = null_function;
        void* data = nullptr;

        void main();
        ~app();
    };
}
