#include <cxxgui/cxxgui.hpp>

namespace cxxgui {

    float view::get_content_width() {
        return body ? body->get_content_width() : 0.0f;
    }

    float view::get_content_height() {
        return body ? body->get_content_height() : 0.0f;
    }

     float view::get_content_box_width() {
        float content_width = style.width;

        if(content_width == 0.0f)
            content_width = get_content_width();

        if(content_width < style.min_width)
            content_width = style.min_width;

        if(content_width > style.max_width && style.max_width != 0.0f)
            content_width = style.max_width;

        return content_width + style.padding_left + style.padding_right;
    }

    float view::get_content_box_height() {
        float content_height = style.height;

        if(content_height == 0.0f)
            content_height = get_content_height();

        if(content_height < style.min_height)
            content_height = style.min_height;

        if(content_height > style.max_height && style.max_height != 0.0f)
            content_height = style.max_height;

        return content_height + style.padding_top + style.padding_bottom;
    }

    float view::get_width() {
        return style.margin_left
             + style.border_left.stroke
             + style.padding_left
             + get_content_box_width()
             + style.padding_right
             + style.border_right.stroke
             + style.margin_right;
    }

    float view::get_height() {
        return style.margin_top
             + style.border_top.stroke
             + style.padding_top
             + get_content_box_height()
             + style.padding_bottom
             + style.border_bottom.stroke
             + style.margin_bottom;
    }

    void view::render_background() {
        // todo: do something about rounded borders here

        float w = get_content_box_width();
        float h = get_content_box_height();

        glBegin(GL_QUADS);

            glColor4f((float)(style.background_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.background_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.background_color >> 8  & 0xFF) / 255.0f,
                      (float)(style.background_color       & 0xFF) / 255.0f);

            glVertex2f(0.0f,  0.0f);
            glVertex2f(w, 0.0f);
            glVertex2f(w, h);
            glVertex2f(0.0f,  h);

        glEnd();
    }

    void view::render_borders() {
        // todo: do something about rounded borders here

        float w = get_content_box_width();
        float h = get_content_box_height();

        if(style.border_top.stroke > 0.0) {
            glColor4f((float)(style.border_top.color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_top.color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_top.color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_top.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(    style.border_top_left_radius,  0.0f);
                glVertex2f(w - style.border_top_right_radius, 0.0f);
                glVertex2f(w - style.border_top_right_radius, style.border_top.stroke);
                glVertex2f(    style.border_top_left_radius,  style.border_top.stroke);

            glEnd();
        }

        if(style.border_right.stroke > 0.0) {
            glColor4f((float)(style.border_right.color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_right.color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_right.color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_right.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(w,                                 style.border_top_right_radius);
                glVertex2f(w + style.border_right.stroke,     style.border_top_right_radius);
                glVertex2f(w + style.border_right.stroke, h - style.border_bottom_right_radius);
                glVertex2f(w,                             h - style.border_bottom_right_radius);

            glEnd();
        }

        if(style.border_bottom.stroke > 0.0) {
            glColor4f((float)(style.border_bottom.color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_bottom.color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_bottom.color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_bottom.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(    style.border_bottom_left_radius,  h + 0.0f);
                glVertex2f(w - style.border_bottom_right_radius, h + 0.0f);
                glVertex2f(w - style.border_bottom_right_radius, h + style.border_bottom.stroke);
                glVertex2f(    style.border_bottom_left_radius,  h + style.border_bottom.stroke);

            glEnd();
        }

        if(style.border_left.stroke > 0.0) {
            glColor4f((float)(style.border_left.color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_left.color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_left.color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_left.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(0.0f,                         style.border_top_left_radius);
                glVertex2f(style.border_left.stroke,     style.border_top_left_radius);
                glVertex2f(style.border_left.stroke, h - style.border_bottom_left_radius);
                glVertex2f(0.0f,                     h - style.border_bottom_left_radius);

            glEnd();
        }
    }

    void view::render() {
        glPushMatrix();

            glTranslatef(style.offset_x + style.margin_left,
                         style.offset_y + style.margin_top,
                         0.0f);
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            float w = get_content_box_width();
            float h = get_content_box_height();

            render_background();
            glPushMatrix();

                glTranslatef(style.border_left.stroke + style.padding_left,
                             style.border_top.stroke + style.padding_top,
                             0.0f);

                int h_alignment = 0;
                int v_alignment = 0;

                switch(style.alignment) {
                    case alignment_t::top_leading:     { h_alignment = 0; v_alignment = 0; break; }
                    case alignment_t::top:             { h_alignment = 1; v_alignment = 0; break; }
                    case alignment_t::top_trailing:    { h_alignment = 2; v_alignment = 0; break; }
                    case alignment_t::leading:         { h_alignment = 0; v_alignment = 1; break; }
                    case alignment_t::center:          { h_alignment = 1; v_alignment = 1; break; }
                    case alignment_t::trailing:        { h_alignment = 2; v_alignment = 1; break; }
                    case alignment_t::bottom_leading:  { h_alignment = 0; v_alignment = 2; break; }
                    case alignment_t::bottom:          { h_alignment = 1; v_alignment = 2; break; }
                    case alignment_t::bottom_trailing: { h_alignment = 2; v_alignment = 2; break; }
                }

                if(h_alignment != 0 || v_alignment != 0) {
                    glPushMatrix();

                        glTranslatef(
                            (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w),
                            (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h),
                            0.0f
                        );
                }

                float x_alignment_offset = body->get_width() + style.padding_left + style.padding_right,
                      y_alignment_offset = body->get_height() + style.padding_top + style.padding_bottom;

                glPushMatrix();

                    if(h_alignment == 0) x_alignment_offset  = 0;
                    if(h_alignment == 1) x_alignment_offset /= 2;
                        
                    if(v_alignment == 0) y_alignment_offset  = 0;
                    if(v_alignment == 1) y_alignment_offset /= 2;

                    glTranslatef(
                        -x_alignment_offset,
                        -y_alignment_offset,
                        0
                    );

                    body->render();

                glPopMatrix();

                if(h_alignment != 0 || v_alignment != 0) {
                    glPopMatrix();
                }

            glPopMatrix();
            render_borders();

        glPopMatrix();
    }

    view* view::frame(float min_w, float ideal_w, float max_w,
                      float min_h, float ideal_h, float max_h,
                      alignment_t alignment) {
        style.min_width = min_w;
        style.width = ideal_w;
        style.max_width = max_w;
        
        style.min_height = min_h;
        style.height = ideal_h;
        style.max_height = max_h;
        
        style.alignment = alignment;
        return this;
    }

    view* view::offset(float x, float y) {
        style.offset_x = x;
        style.offset_y = y;
        return this;
    }

    view* view::margin(float margin) {
        style.margin_top = margin;
        style.margin_right = margin;
        style.margin_bottom = margin;
        style.margin_left = margin;
        return this;
    }

    view* view::margin(float vertical, float horizontal) {
        style.margin_top = vertical;
        style.margin_right = horizontal;
        style.margin_bottom = vertical;
        style.margin_left = horizontal;
        return this;
    }

    view* view::margin(float top, float right, float bottom, float left) {
        style.margin_top = top;
        style.margin_right = right;
        style.margin_bottom = bottom;
        style.margin_left = left;
        return this;
    }

    view* view::padding(float padding) {
        style.padding_top = padding;
        style.padding_right = padding;
        style.padding_bottom = padding;
        style.padding_left = padding;
        return this;
    }

    view* view::padding(float vertical, float horizontal) {
        style.padding_top = vertical;
        style.padding_right = horizontal;
        style.padding_bottom = vertical;
        style.padding_left = horizontal;
        return this;
    }

    view* view::padding(float top, float right, float bottom, float left) {
        style.padding_top = top;
        style.padding_right = right;
        style.padding_bottom = bottom;
        style.padding_left = left;
        return this;
    }

    view* view::border(border_t border) {
        style.border_top = border;
        style.border_right = border;
        style.border_bottom = border;
        style.border_left = border;
        return this;
    }

    view* view::border(border_t vertical, border_t horizontal) {
        style.border_top = vertical;
        style.border_right = horizontal;
        style.border_bottom = vertical;
        style.border_left = horizontal;
        return this;
    }

    view* view::border(border_t top, border_t right, border_t bottom, border_t left) {
        style.border_top = top;
        style.border_right = right;
        style.border_bottom = bottom;
        style.border_left = left;
        return this;
    }

    view* view::border_radius(float radius) {
        style.border_top_left_radius = radius;
        style.border_top_right_radius = radius;
        style.border_bottom_right_radius = radius;
        style.border_bottom_left_radius = radius;
        return this;
    }

    view* view::border_radius(float top_left, float top_right, float bottom_right, float bottom_left) {
        style.border_top_left_radius = top_left;
        style.border_top_right_radius = top_right;
        style.border_bottom_right_radius = bottom_right;
        style.border_bottom_left_radius = bottom_left;
        return this;
    }

    view* view::background_color(uint32_t color) {
        style.background_color = color;
        return this;
    }

    view* view::foreground_color(uint32_t color) {
        style.color = color;
        return this;
    }

    view* view::rotation(float degrees) {
        style.rotation = degrees;
        return this;
    }

    /*
     * View stacks
     */

    float stack::get_content_width() {
        float content_width = 0.0f;

        for(view* v : content)
            if(dir == stack_direction::horizontal)
                content_width += v->get_width();
            else if(v->get_width() > content_width)
                content_width = v->get_width();

        return content_width;
    }

    float stack::get_content_height() {
        float content_height = 0.0f;

        for(view* v : content)
            if(dir == stack_direction::vertical)
                content_height += v->get_height();
            else if(v->get_height() > content_height)
                content_height = v->get_height();

        return content_height;
    }

    void stack::render() {
        glPushMatrix();

            glTranslatef(style.offset_x + style.margin_left,
                         style.offset_y + style.margin_top,
                         0.0f);
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            float w = get_content_box_width();
            float h = get_content_box_height();

            render_background();

            glPushMatrix();

                glTranslatef(style.border_left.stroke + style.padding_left,
                             style.border_top.stroke + style.padding_top,
                             0.0f);

                float x_offset = 0.0f,
                      y_offset = 0.0f,
                      z_offset = 0.0f;

                for(view* v : content) {

                    //glScissor(0, 0, width, height); doesn't work - will have to google how glScissor works I suppose
                    
                    int h_alignment = 0;
                    int v_alignment = 0;

                    switch(style.alignment) {
                        case alignment_t::top_leading:     { h_alignment = 0; v_alignment = 0; break; }
                        case alignment_t::top:             { h_alignment = 1; v_alignment = 0; break; }
                        case alignment_t::top_trailing:    { h_alignment = 2; v_alignment = 0; break; }
                        case alignment_t::leading:         { h_alignment = 0; v_alignment = 1; break; }
                        case alignment_t::center:          { h_alignment = 1; v_alignment = 1; break; }
                        case alignment_t::trailing:        { h_alignment = 2; v_alignment = 1; break; }
                        case alignment_t::bottom_leading:  { h_alignment = 0; v_alignment = 2; break; }
                        case alignment_t::bottom:          { h_alignment = 1; v_alignment = 2; break; }
                        case alignment_t::bottom_trailing: { h_alignment = 2; v_alignment = 2; break; }
                    }

                    if(h_alignment != 0 || v_alignment != 0) {
                        glPushMatrix();

                            glTranslatef(
                                (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w),
                                (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h),
                                0.0f
                            );
                    }

                    float w = v->get_width(),
                          h = v->get_height();

                    glPushMatrix();

                        float x_alignment_offset = w,
                              y_alignment_offset = h;

                        if(dir == stack_direction::horizontal) x_alignment_offset = get_content_width();
                        if(dir == stack_direction::vertical)   y_alignment_offset = get_content_height();

                        if(h_alignment == 0) x_alignment_offset = 0;
                        if(h_alignment == 1) x_alignment_offset /= 2;

                        if(v_alignment == 0) y_alignment_offset = 0;
                        if(v_alignment == 1) y_alignment_offset /= 2;

                        glTranslatef(
                            x_offset - x_alignment_offset,
                            y_offset - y_alignment_offset ,
                            z_offset
                        );

                        v->render();

                    glPopMatrix();

                    if(h_alignment != 0 || v_alignment != 0) {
                        glPopMatrix();
                    }

                    switch(dir) {
                        case stack_direction::horizontal: x_offset += w; break;
                        case stack_direction::vertical:   y_offset += h; break;
                        case stack_direction::depth:                     break;
                    }
                }

            glPopMatrix();

            render_borders();

        glPopMatrix();
    }

}
