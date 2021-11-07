#include <cxxgui/cxxgui.hpp>
#if defined(_WIN32) || defined(_WIN64)
# include <Windows.h>
# include <VersionHelpers.h>

namespace cxxgui {

    namespace settings {

        bool supports_dark_mode() { return IsWindows8OrGreater(); }
        bool is_dark_mode() {
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

    }

}
#endif
