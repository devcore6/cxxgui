#include <string>
#include <vector>
#include <initializer_list>
#include <functional>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include <cxxgui/color.hpp>
#include <cxxgui/style.hpp>
#include <cxxgui/view.hpp>
#include <cxxgui/window.hpp>


namespace cxxgui {
	bool null_function(window_t* self, void* data) {
		return true;
	}
}
