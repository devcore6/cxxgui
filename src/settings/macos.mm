#include <cxxgui/cxxgui.hpp>
#if defined(__APPLE__) && defined(__MACH__)
# import <Foundation/Foundation.h>
# import <AppKit/AppKit.h>

namespace cxxgui {

	namespace settings {
		bool supports_dark_mode() { return @available(macOS 11.0, *); }
		bool is_dark_mode() {
			if(!supports_dark_mode()) return false;
			return [NSApplication.sharedApplication.effectiveAppearance.name.lowercaseString rangeOfString:@"dark"].location != NSNotFound;
		}
	}

}
#endif
