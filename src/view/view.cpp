#include <cxxgui/cxxgui.hpp>

namespace cxxgui {

    GLfloat view::get_content_width() {
        GLfloat content_width = style.width;

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

    GLfloat view::get_content_height() {
        GLfloat content_height = style.height;

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

    GLfloat view::get_width() {
        return style.margin_left
              + style.border_left
              + style.padding_left
              + get_content_width()
              + style.padding_right
              + style.border_right
              + style.margin_right;
    }

    GLfloat view::get_height() {
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

            glTranslatef(style.translate_x, style.translate_y, 0.0f);
            glRotatef(style.rotation, 0.0f, 0.0f, 1.0f);

            // todo: do something to render borders here

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
    }

}
