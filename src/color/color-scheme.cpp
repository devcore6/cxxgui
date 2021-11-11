#include <cstdint>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>

#include <cxxgui/settings.hpp>
#include <cxxgui/color.hpp>

namespace cxxgui {

	namespace color {

		uint32_t get_background() { return settings::is_dark_mode() ? black : white; }
		uint32_t get_foreground() { return settings::is_dark_mode() ? white : black; }

		uint32_t background = get_background();
		uint32_t foreground = get_foreground();
		uint32_t accent_color = settings::get_accent_color();

	}

}
