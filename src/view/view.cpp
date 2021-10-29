#include <cxxgui/cxxgui.hpp>

namespace cxxgui {

    float view::get_content_width() {
        float content_width = 0.0f;

        for(view* v : data.first)
            if(data.second == stack_direction::horizontal)
                content_width += v->get_width();
            else if(v->get_width() > content_width)
                content_width = v->get_width();

        return content_width;
    }

    float view::get_content_height() {
        float content_height = 0.0f;

        for(view* v : data.first)
            if(data.second == stack_direction::vertical)
                content_height += v->get_height();
            else if(v->get_height() > content_height)
                content_height = v->get_height();

        return content_height;
    }

     float view::get_content_box_width() {
        float content_width = style.width;

        if(content_width == 0.0f)
            content_width = get_content_width();

        if(content_width < style.min_width)
            content_width = style.min_width;

        if(content_width > style.max_width && style.max_width != 0.0f)
            content_width = style.max_width;

        return content_width;
    }

    float view::get_content_box_height() {
        float content_height = style.height;

        if(content_height == 0.0f)
            content_height = get_content_height();

        if(content_height < style.min_height)
            content_height = style.min_height;

        if(content_height > style.max_height && style.max_height != 0.0f)
            content_height = style.max_height;

        return content_height;
    }

    float view::get_width() {
        return style.margin_left
              + style.border_left
              + style.padding_left
              + get_content_box_width()
              + style.padding_right
              + style.border_right
              + style.margin_right;
    }

    float view::get_height() {
        return style.margin_top
              + style.border_top
              + style.padding_top
              + get_content_box_height()
              + style.padding_bottom
              + style.border_bottom
              + style.margin_bottom;
    }

    void view::render_background() {
        // todo: do something about rounded borders here

        float width = get_content_box_width();
        float height = get_content_box_height();

        glBegin(GL_QUADS);

            glColor4f((float)(style.background_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.background_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.background_color >> 8  & 0xFF) / 255.0f,
                      (float)(style.background_color       & 0xFF) / 255.0f);

            glVertex2f(0.0f,  0.0f);
            glVertex2f(width, 0.0f);
            glVertex2f(width, height);
            glVertex2f(0.0f,  height);

        glEnd();
    }

    void view::render_borders() {
        // todo: do something about rounded borders here

        float width = get_content_box_width();
        float height = get_content_box_height();

        if(style.border_top > 0.0) {
            glColor4f((float)(style.border_top_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_top_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_top_color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_top_color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(        style.border_top_left_radius,  0.0f);
                glVertex2f(width - style.border_top_right_radius, 0.0f);
                glVertex2f(width - style.border_top_right_radius, style.border_top);
                glVertex2f(        style.border_top_left_radius,  style.border_top);

            glEnd();
        }

        if(style.border_right > 0.0) {
            glColor4f((float)(style.border_right_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_right_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_right_color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_right_color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(width,                               style.border_top_right_radius);
                glVertex2f(width + style.border_right,          style.border_top_right_radius);
                glVertex2f(width + style.border_right, height - style.border_bottom_right_radius);
                glVertex2f(width,                      height - style.border_bottom_right_radius);

            glEnd();
        }

        if(style.border_bottom > 0.0) {
            glColor4f((float)(style.border_bottom_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_bottom_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_bottom_color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_bottom_color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(        style.border_bottom_left_radius,  height + 0.0f);
                glVertex2f(width - style.border_bottom_right_radius, height + 0.0f);
                glVertex2f(width - style.border_bottom_right_radius, height + style.border_bottom);
                glVertex2f(        style.border_bottom_left_radius,  height + style.border_bottom);

            glEnd();
        }

        if(style.border_left > 0.0) {
            glColor4f((float)(style.border_left_color >> 24 & 0xFF) / 255.0f,
                      (float)(style.border_left_color >> 16 & 0xFF) / 255.0f,
                      (float)(style.border_left_color >>  8 & 0xFF) / 255.0f,
                      (float)(style.border_left_color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(0.0f,                       style.border_top_left_radius);
                glVertex2f(style.border_left,          style.border_top_left_radius);
                glVertex2f(style.border_left, height - style.border_bottom_left_radius);
                glVertex2f(0.0f,              height - style.border_bottom_left_radius);

            glEnd();
        }
    }

    void view::init() {
        for(view* v : data.first)
            v->init();
    }

    void view::render() {
        glPushMatrix();

            glTranslatef(style.translate_x + style.margin_left,
                         style.translate_y + style.margin_top,
                         0.0f);
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            float width = get_content_box_width();
            float height = get_content_box_height();

            render_background();
            render_borders();

            glPushMatrix();

                glTranslatef(style.border_left + style.padding_left,
                             style.border_top + style.padding_top,
                             0.0f);

                float x_offset = 0.0f,
                      y_offset = 0.0f,
                      z_offset = 0.0f;

                for(view* v : data.first) {

                    //glScissor(0, 0, width, height); doesn't work

                    if(style.horizontal_align != align::left && style.vertical_align != align::top) {
                        glPushMatrix();

                        glTranslatef(
                            (style.horizontal_align == align::left) ? 0 : (style.horizontal_align == align::center) ? width / 2 : width,
                            (style.vertical_align == align::top) ? 0 : (style.vertical_align == align::center) ? height / 2 : height,
                            0.0f
                        );
                    }

                    float w = v->get_width(),
                          h = v->get_height();

                    glPushMatrix();

                        float x_alignment_offset = w;
                        float y_alignment_offset = h;

                        if(data.second == stack_direction::horizontal) x_alignment_offset = get_content_width();
                        if(data.second == stack_direction::vertical)   y_alignment_offset = get_content_height();

                        if(style.horizontal_align == align::left)   x_alignment_offset  = 0;
                        if(style.horizontal_align == align::center) x_alignment_offset /= 2;
                        if(style.horizontal_align == align::right)  x_alignment_offset += style.margin_right;
                        
                        if(style.vertical_align   == align::top)    y_alignment_offset  = 0;
                        if(style.vertical_align   == align::center) y_alignment_offset /= 2;
                        if(style.vertical_align   == align::bottom) y_alignment_offset += style.margin_bottom;

                        glTranslatef(
                            x_offset - x_alignment_offset,
                            y_offset - y_alignment_offset ,
                            z_offset
                        );

                        v->render();

                    glPopMatrix();

                    if(style.horizontal_align != align::left && style.vertical_align != align::top) {
                        glPopMatrix();
                    }

                    switch(data.second) {
                        case stack_direction::horizontal: x_offset += w; break;
                        case stack_direction::vertical:   y_offset += h; break;
                        case stack_direction::depth:                     break;
                    }
                }

            glPopMatrix();

        glPopMatrix();
    }

}
