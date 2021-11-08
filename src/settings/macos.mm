#include <cxxgui/cxxgui.hpp>
# import <CoreServices/CoreServices.h>
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

        bool supports_transparency() {
            int32_t majorVersion, minorVersion;

            Gestalt(gestaltSystemVersionMajor, &majorVersion);
            Gestalt(gestaltSystemVersionMinor, &minorVersion);
            Gestalt(gestaltSystemVersionBugFix, &bugFixVersion);

            return !(majorVersion < 10 || (majorVersion == 10 && minorVersion < 10));
        }

        bool has_transparency_enabled() {
            // This is not really correct as there is a setting to disable transparency
            // But I will have to check how that works once I reinstall macOS.
            return supports_transparency();
        }


        uint32_t get_accent_color() {
            int32_t majorVersion, minorVersion;

            Gestalt(gestaltSystemVersionMajor, &majorVersion);
            Gestalt(gestaltSystemVersionMinor, &minorVersion);
            Gestalt(gestaltSystemVersionBugFix, &bugFixVersion);

            if(majorVersion < 10 || (majorVersion == 10 && minorVersion < 14)) return color::blue;

            // I have no idea, I need to install macOS again and test it out for myself.
            // It should be stored in AppleAccentColor, I believe

            return color::blue;
        }

    }

}
