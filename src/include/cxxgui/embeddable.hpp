#pragma once
#include "view.hpp"
#include <SDL/SDL.h>

namespace cxxgui {
    class embeddable : public view {
    protected:
        friend class view;

    public:
        view* body = nullptr;
        void render_gui(bool clicking, bool send_click, int lastx, int lasty, float width_scale, float height_scale) {
            if(!body) return;
            int x = 0, y = 0;
            SDL_GetMouseState(&x, &y);
            float rel_x = (float)x * width_scale, rel_y = (float)y * height_scale;
            body->do_render(rel_x, rel_y, clicking, send_click, lastx, lasty);
        }
    };
}
