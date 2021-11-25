#pragma once

namespace cxxgui {
    extern void glClippingFrame(int x, int y, int w, int h);
    extern void glPushClippingFrame();
    extern void glPopClippingFrame();
    extern void glClearClippingFrames();
}
