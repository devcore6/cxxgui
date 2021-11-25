#include <string>
#include <vector>
#include <functional>
#include <iomanip>
#include <sstream>
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include <cxxgui/utilities.hpp>
#include <cxxgui/gl.hpp>

namespace cxxgui {
    struct clipping_frame {
        int x = 0;
        int y = 0;
        int w = 0;
        int h = 0;
    };

    std::vector<clipping_frame> clipping_frames;
    clipping_frame active_clipping_frame = { 0, 0, 0, 0 };
    bool has_clipping_frame = false;

    void update_scissor() {
        if(!has_clipping_frame) return;

        int x = active_clipping_frame.x;
        int y = active_clipping_frame.y;

        for(auto& cur : clipping_frames) {
            x += cur.x;
            y += cur.y;
        }
        
        int m_viewport[4];
        glGetIntegerv(GL_VIEWPORT, m_viewport);
        glScissor(x, m_viewport[3] - y - active_clipping_frame.h, active_clipping_frame.w, active_clipping_frame.h);
    }

    void glClippingFrame(int x, int y, int w, int h) {
        clipping_frame cur = { x, y, w, h };

        if(has_clipping_frame) {
            int clamped_x = clamp(0, x, active_clipping_frame.w);
            int clamped_y = clamp(0, y, active_clipping_frame.h);

            cur = {
                clamped_x,
                clamped_y,
                clamp(0, w, active_clipping_frame.w - clamped_x),
                clamp(0, h, active_clipping_frame.h - clamped_y)
            };
        } else {
            has_clipping_frame = true;
            glEnable(GL_SCISSOR_TEST);
        }

        active_clipping_frame = cur;
        update_scissor();
    }

    void glPushClippingFrame() {
        clipping_frames.push_back(active_clipping_frame);
        active_clipping_frame.x = 0;
        active_clipping_frame.y = 0;
    }

    void glPopClippingFrame() {
        clipping_frames.pop_back();
        if(clipping_frames.size() != 0) {
            active_clipping_frame = clipping_frames[clipping_frames.size() - 1];
            update_scissor();
        } else {
            has_clipping_frame = false;
            glDisable(GL_SCISSOR_TEST);
        }
    }

    void glClearClippingFrames() {
        has_clipping_frame = false;
        clipping_frames.clear();

        glDisable(GL_SCISSOR_TEST);
    }
}
