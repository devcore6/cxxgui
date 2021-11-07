#include <cxxgui/cxxgui.hpp>
# import <Foundation/Foundation.h>
# import <AppKit/AppKit.h>

namespace cxxgui {

	namespace settings {

		bool supports_dark_mode() {
			return [[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"] != nil;
		}
		bool is_dark_mode() {
			NSString *color_scheme = [[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"];
			return (color_scheme == nil) ? false : (color_scheme == @"dark");
		}

	}

}
