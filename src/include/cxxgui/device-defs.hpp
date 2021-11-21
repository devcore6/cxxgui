#ifndef __APPLE__
# define __CXXGUI_DESKTOP__ // this will probably need more ifdefs here later on
#else
# if (TARGET_OS_IOS)
#  define __CXXGUI_IOS__
#  define __CXXGUI_PHONE__
# endif
# if (TARGET_OS_TV)
#  define __CXXGUI_TVOS__
# endif
# if (TARGET_OS_WATCH)
#  define __CXXGUI_WATCHOS__
# endif
# if (TARGET_OS_MAC)
#  define __CXXGUI_MACOS__
#  define __CXXGUI_DESKTOP__
# endif
#endif
