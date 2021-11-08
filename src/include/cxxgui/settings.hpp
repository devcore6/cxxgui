#pragma once

namespace cxxgui {

    namespace settings {

        extern bool supports_dark_mode();
        extern bool is_dark_mode();

        extern bool supports_transparency();
        extern bool has_transparency_enabled();
    
        extern uint32_t get_accent_color();

    }

}
