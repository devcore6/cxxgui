#include <cxxgui/cxxgui.hpp>

namespace cxxgui {

    float view::get_content_width() {
        float content_width = style.width;

        if(content_width == 0.0f)
            for(view v : data.first)
                if(data.second == stack_direction::horizontal)
                    content_width += v.get_width();
                else if(v.get_width() > content_width)
                    content_width = v.get_width();

        if(content_width < style.min_width)
            content_width = style.min_width;

        if(content_width > style.max_width && style.max_width != 0.0f)
            content_width = style.max_width;

        return content_width;
    }

    float view::get_content_height() {
        float content_height = style.height;

        if(content_height == 0.0f)
            for(view v : data.first)
                if(data.second == stack_direction::horizontal)
                    content_height += v.get_height();
                else if(v.get_height() > content_height)
                    content_height = v.get_height();

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
              + get_content_width()
              + style.padding_right
              + style.border_right
              + style.margin_right;
    }

    float view::get_height() {
        return style.margin_top
              + style.border_top
              + style.padding_top
              + get_content_height()
              + style.padding_bottom
              + style.border_bottom
              + style.margin_bottom;
    }

    void view::render() {
        glPushMatrix();

            glTranslatef(style.translate_x + style.margin_left,
                         style.translate_y + style.margin_top,
                         1.0f);
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            // todo: do something about rounded borders here

            float width = get_content_width();
            float height = get_content_height();

            if(style.border_top > 0.0) {
                glColor4f((float)(style.border_top_color >> 24 & 0xFF) / 255.0f,
                          (float)(style.border_top_color >> 16 & 0xFF) / 255.0f,
                          (float)(style.border_top_color >>  8 & 0xFF) / 255.0f,
                          (float)(style.border_top_color & 0xFF) / 255.0f);

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
                          (float)(style.border_right_color >>  8 & 0xFF)/ 255.0f,
                          (float)(style.border_right_color & 0xFF) / 255.0f);

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
                          (float)(style.border_bottom_color & 0xFF) / 255.0f);

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
                          (float)(style.border_left_color >>  8 & 0xFF)/ 255.0f,
                          (float)(style.border_left_color & 0xFF) / 255.0f);

                glBegin(GL_QUADS);

                    glVertex2f(0.0f,                       style.border_top_left_radius);
                    glVertex2f(style.border_left,          style.border_top_left_radius);
                    glVertex2f(style.border_left, height - style.border_bottom_left_radius);
                    glVertex2f(0.0f,              height - style.border_bottom_left_radius);

                glEnd();
            }

            glPushMatrix();

                glTranslatef(style.border_left + style.padding_left,
                             style.border_top + style.padding_top,
                             1.0f);

                GLfloat x_offset = 0.0f,
                        y_offset = 0.0f,
                        z_offset = 0.0f;

                for(view v : data.first) {
                    glPushMatrix();

                        glTranslatef(x_offset, y_offset, z_offset);

                        v.render();

                    glPopMatrix();

                    switch(data.second) {
                        case stack_direction::horizontal: x_offset += v.get_width();  break;
                        case stack_direction::vertical:   y_offset += v.get_height(); break;
                        case stack_direction::depth:      z_offset ++;                break;
                    }
                }

            glPopMatrix();

        glPopMatrix();
    }

}
