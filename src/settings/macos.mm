#include <cstdint>
#include <cxxgui/settings.hpp>
#include <cxxgui/color.hpp>
#import <Availability.h>
#import <CoreServices/CoreServices.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

namespace cxxgui {

    namespace settings {

        bool supports_dark_mode() {
            return [[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"] != nil;
        }

        bool is_dark_mode() {
            NSString *color_scheme = [[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"];
            return (color_scheme == nil) ? false : ([color_scheme  isEqual: @"dark"]);
        }

        bool supports_transparency() {
#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 1010
            return true;
#else
            return false;
#endif
        }

        bool has_transparency_enabled() {
            // This is not really correct as there is a setting to disable transparency
            // But I will have to check how that works once I reinstall macOS.
            return supports_transparency();
        }


        uint32_t get_accent_color() {
#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 1014
            NSColor *accent_color = NSColor.controlAccentColor;
            return ((uint32_t)(accent_color.redComponent   * 255.0f) & 0xFF) << 24 |
                   ((uint32_t)(accent_color.greenComponent * 255.0f) & 0xFF) << 16 |
                   ((uint32_t)(accent_color.blueComponent  * 255.0f) & 0xFF) << 8 |
                   ((uint32_t)(accent_color.alphaComponent * 255.0f) & 0xFF);
#else
            return color::blue;
#endif
        }

    }

}
