#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <filesystem>
#include <thread>
#include <atomic>
#include <future>
#include <mutex>
#include <chrono>
#include <functional>

#if defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
# define __CXXGUI_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
# define __CXXGUI_MACOS
#elif defined(_WIN32) || defined(_WIN64)
# define __CXXGUI_WINDOWS
#endif

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include <gl/GLU.h>

#include "style.hpp"
#include "view.hpp"
#include "font.hpp"
#include "text.hpp"
#include "window.hpp"
