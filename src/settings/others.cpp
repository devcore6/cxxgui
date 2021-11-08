#include <cxxgui/cxxgui.hpp>
#if !(defined(__APPLE__) && defined(__MACH__)) && !(defined(_WIN32) || defined(_WIN64))
namespace cxxgui {

	namespace settings {

		// todo: maybe in the future add some DE-dependent checks here
		//       as I assume that some DEs actually do have dark mode
		//       support. I don't know, it's probably not worth the
		//       effort and at least for now there's more important
		//       stuff to work on.

		bool supports_dark_mode() { return false; }
		bool is_dark_mode() { return false; }

		// todo: again, DE-dependent checks here

		bool supports_transparency() { return false; }
		bool has_transparency_enabled() { return false; }

		// todo: again, DE-dependent checks here

		uint32_t get_accent_color() { return color::blue; }

	}

}
#endif
