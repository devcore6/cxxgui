#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include <functional>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#define GL_GLEXT_PROTOTYPES
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include "device-defs.hpp"
#include "utilities.hpp"
#include "settings.hpp"
#include "color.hpp"
#include "style.hpp"
#include "view.hpp"
#include "font.hpp"
#include "text.hpp"
#include "image.hpp"
#include "symbols.hpp"
#include "symbols_list.hpp"
#include "animation.hpp"
#include "input.hpp"
#include "window.hpp"
