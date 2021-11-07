#include <cxxgui/cxxgui.hpp>
#if !(defined(__APPLE__) && defined(__MACH__)) && !(defined(_WIN32) || defined(_WIN64))
namespace cxxgui {

	namespace settings {

		bool supports_dark_mode() { return false; }
		bool is_dark_mode() { return false; }

	}

}
#endif
