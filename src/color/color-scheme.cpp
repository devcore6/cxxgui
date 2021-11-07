#include <cxxgui/cxxgui.hpp>

namespace cxxgui {

	namespace color {

		uint32_t background() { return settings::is_dark_mode() ? black : white; }
		uint32_t foreground() { return settings::is_dark_mode() ? white : black; }

	}

}
