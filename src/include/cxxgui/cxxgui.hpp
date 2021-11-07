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

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include <gl/GLU.h>

#include "settings.hpp"
#include "color.hpp"
#include "style.hpp"
#include "view.hpp"
#include "font.hpp"
#include "text.hpp"
#include "window.hpp"
