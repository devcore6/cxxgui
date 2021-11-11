#if defined(_WIN32) || defined(_WIN64)
# include <thread>
# include <chrono>

# define SDL_MAIN_HANDLED
# include <SDL/SDL.h>

# include <cxxgui/settings.hpp>
# include <cxxgui/color.hpp>

# include <Windows.h>
# include <VersionHelpers.h>

/*
 * I don't even wanna ask why I need to fix Windows'
 * stupid WinRT/C++ library, but some genius in the
 * dev team typod sleep_for as wait_for in one of the
 * headers... Supposedly it's fixed (I don't actually
 * know for sure cause the information online was
 * basically non-existing) in newer versions of
 * WinRT/C++, but I'm on VisualStudio 2022 with the
 * latest SDK version and it still doesn't work.
 * 
 * Perhaps WinRT/C++ works for others, but I can't
 * know that for certain, so I have to just assume
 * they never actually fixed it, and that I have to
 * fix it myself if I want to use it in my library,
 * which sadly I do have to as it's the only way to
 * get the user's selected accent color (or at the
 * very least it's the only documented way, and
 * calling it documented is already a stretch since
 * MicroSoft's documentations are always trash...
 * 
 * Seriously, how hard is it to proof read your code
 * and how hard is it to make a decent API
 * documentation, Objective-C is dog shit but at
 * least Apple has proper documentation on their
 * site...
 * 
 * Okay, that was a long rant, well, since someone
 * in the dev team typod sleep_for as wait_for I
 * have to create a wait_for function now to make
 * WinRT/C++ actually work. This is literally just
 * calling std::this_thread::sleep_for, but I don't
 * care if it's wrong and if wait_for is actually
 * not a typo and is actually a function that exists
 * somewhere else in other Windows libraries - the
 * documentation online is literally non-existing
 * and this seems to work so good enough and once
 * again, curse you MicroSoft, that's 3 hours of my
 * life trying to look into why your stupid library
 * doesn't work that I'm not getting back.
 * 
 * If the question of why make a GUI library still
 * exists in someone's mind, this is the answer.
 * Because fuck OS APIs (mostly Windows' ones).
 */

namespace winrt {
    namespace impl {
        template <class _Rep, class _Period>
        void wait_for(const std::chrono::duration<_Rep, _Period>& _Rel_time) {
            std::this_thread::sleep_for(_Rel_time);
        }
    }
}

#include <winrt/Windows.UI.ViewManagement.h>

namespace cxxgui {

    namespace settings {

        bool supports_dark_mode() { return IsWindows8OrGreater(); }
        bool is_dark_mode() {
            // This could be replaced with a WinRT function,
            // But I believe this is better, plus, it's also easier.

            if(!supports_dark_mode()) return false;
            HKEY hkey;

            if(RegOpenKeyEx(
                HKEY_CURRENT_USER,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                0,
                KEY_QUERY_VALUE,
                &hkey
            ) != ERROR_SUCCESS) return false;

            DWORD buffer_size = sizeof(DWORD);
            DWORD value = 0;

            if(RegQueryValueEx(
                hkey,
                L"AppsUseLightTheme",
                NULL,
                NULL,
                reinterpret_cast<LPBYTE>(&value),
                &buffer_size
            ) != ERROR_SUCCESS) {
                RegCloseKey(hkey);
                return false;
            }

            RegCloseKey(hkey);
            return value == 0;

        }

        bool supports_transparency() { return IsWindows10OrGreater(); }
        bool has_transparency_enabled() {

            if(!supports_transparency()) return false;
            HKEY hkey;

            if(RegOpenKeyEx(
                HKEY_CURRENT_USER,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                0,
                KEY_QUERY_VALUE,
                &hkey
            ) != ERROR_SUCCESS) return false;

            DWORD buffer_size = sizeof(DWORD);
            DWORD value = 0;

            if(RegQueryValueEx(
                hkey,
                L"EnableTransparency",
                NULL,
                NULL,
                reinterpret_cast<LPBYTE>(&value),
                &buffer_size
            ) != ERROR_SUCCESS) {
                RegCloseKey(hkey);
                return false;
            }

            RegCloseKey(hkey);
            return value == 0;
        }

        uint32_t get_accent_color() {
            if(!IsWindows8OrGreater()) return color::blue;

            winrt::Windows::UI::ViewManagement::UISettings const ui_settings{};

            auto const accent_color = ui_settings.GetColorValue(winrt::Windows::UI::ViewManagement::UIColorType::Accent);

            return (accent_color.R << 24) | (accent_color.G << 16) | (accent_color.B << 8) | accent_color.A;
        }

    }

}
#endif
