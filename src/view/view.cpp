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

namespace cxxgui {

    float linear(float step, float pos) {
        return pos + step;
    }

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

        return content_width + rendered_style->padding_left + rendered_style->padding_right;
    }

    float view::get_content_box_height() {
        float content_height = style.height;

        if(content_height == 0.0f)
            content_height = get_content_height();

        if(content_height < style.min_height)
            content_height = style.min_height;

        if(content_height > style.max_height && style.max_height != 0.0f)
            content_height = style.max_height;

        return content_height + rendered_style->padding_top + rendered_style->padding_bottom;
    }

    float view::get_width() {
        return rendered_style->margin_left
             + rendered_style->border_left.stroke
             + rendered_style->padding_left
             + get_content_box_width()
             + rendered_style->padding_right
             + rendered_style->border_right.stroke
             + rendered_style->margin_right;
    }

    float view::get_height() {
        return rendered_style->margin_top
             + rendered_style->border_top.stroke
             + rendered_style->padding_top
             + get_content_box_height()
             + rendered_style->padding_bottom
             + rendered_style->border_bottom.stroke
             + rendered_style->margin_bottom;
    }

    void view::render_background() {
        // todo: do something about rounded borders here

        float w = get_content_box_width();
        float h = get_content_box_height();

        glBegin(GL_QUADS);

            glColor4f((float)(rendered_style->background_color >> 24 & 0xFF) / 255.0f,
                      (float)(rendered_style->background_color >> 16 & 0xFF) / 255.0f,
                      (float)(rendered_style->background_color >> 8  & 0xFF) / 255.0f,
                      (float)(rendered_style->background_color       & 0xFF) / 255.0f);

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

        if(rendered_style->border_top.stroke > 0.0) {
            glColor4f((float)(rendered_style->border_top.color >> 24 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_top.color >> 16 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_top.color >>  8 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_top.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(    rendered_style->border_top_left_radius,  0.0f);
                glVertex2f(w - rendered_style->border_top_right_radius, 0.0f);
                glVertex2f(w - rendered_style->border_top_right_radius, rendered_style->border_top.stroke);
                glVertex2f(    rendered_style->border_top_left_radius,  rendered_style->border_top.stroke);

            glEnd();
        }

        if(rendered_style->border_right.stroke > 0.0) {
            glColor4f((float)(rendered_style->border_right.color >> 24 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_right.color >> 16 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_right.color >>  8 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_right.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(w,                                           rendered_style->border_top_right_radius);
                glVertex2f(w + rendered_style->border_right.stroke,     rendered_style->border_top_right_radius);
                glVertex2f(w + rendered_style->border_right.stroke, h - rendered_style->border_bottom_right_radius);
                glVertex2f(w,                                       h - rendered_style->border_bottom_right_radius);

            glEnd();
        }

        if(rendered_style->border_bottom.stroke > 0.0) {
            glColor4f((float)(rendered_style->border_bottom.color >> 24 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_bottom.color >> 16 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_bottom.color >>  8 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_bottom.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);
                    
                glVertex2f(    rendered_style->border_bottom_left_radius,  h + 0.0f);
                glVertex2f(w - rendered_style->border_bottom_right_radius, h + 0.0f);
                glVertex2f(w - rendered_style->border_bottom_right_radius, h + rendered_style->border_bottom.stroke);
                glVertex2f(    rendered_style->border_bottom_left_radius,  h + rendered_style->border_bottom.stroke);

            glEnd();
        }

        if(rendered_style->border_left.stroke > 0.0) {
            glColor4f((float)(rendered_style->border_left.color >> 24 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_left.color >> 16 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_left.color >>  8 & 0xFF) / 255.0f,
                      (float)(rendered_style->border_left.color       & 0xFF) / 255.0f);

            glBegin(GL_QUADS);

                glVertex2f(0.0f,                                   rendered_style->border_top_left_radius);
                glVertex2f(rendered_style->border_left.stroke,     rendered_style->border_top_left_radius);
                glVertex2f(rendered_style->border_left.stroke, h - rendered_style->border_bottom_left_radius);
                glVertex2f(0.0f,                               h - rendered_style->border_bottom_left_radius);

            glEnd();
        }
    }

    void view::render() {
        glPushMatrix();

            glTranslatef(rendered_style->offset_x + rendered_style->margin_left,
                         rendered_style->offset_y + rendered_style->margin_top,
                         0.0f);
            glRotatef(rendered_style->rotation, 0.0f, 0.0f, 1.0f);

            // todo: this fully ignores rotation for now
            float x_off = rendered_style->offset_x + rendered_style->margin_left;
            float y_off = rendered_style->offset_y + rendered_style->margin_top;

            float w = get_content_box_width();
            float h = get_content_box_height();

            render_background();
            glPushMatrix();

                glTranslatef(rendered_style->border_left.stroke + rendered_style->padding_left,
                             rendered_style->border_top.stroke + rendered_style->padding_top,
                             0.0f);

                x_off += rendered_style->border_left.stroke + rendered_style->padding_left;
                y_off += rendered_style->border_top.stroke + rendered_style->padding_top;

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

                if(style.alignment != alignment_t::top_leading) {
                    glPushMatrix();

                        glTranslatef(
                            (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w),
                            (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h),
                            0.0f
                        );

                        x_off += (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w);
                        y_off += (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h);
                }

                float x_alignment_offset = body ? body->get_width() : 0 + rendered_style->padding_left + rendered_style->padding_right,
                      y_alignment_offset = body ? body->get_height() : 0 + rendered_style->padding_top + rendered_style->padding_bottom;

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

                    x_off -= x_alignment_offset;
                    y_off -= y_alignment_offset;

                    // this is an awful solution, but I can't be bothered editing all the individual render functions right now
                    // as such, it's fine and it'll do for now.
                    // todo: change this later

                    if(body) body->do_render(
                        __rel_x - x_off,
                        __rel_y - y_off,
                        __clicking,
                        __send_click,
                        (int)(__last_x - x_off),
                        (int)(__last_y - y_off)
                    );

                glPopMatrix();

                if(style.alignment != alignment_t::top_leading) {
                    glPopMatrix();
                }

            glPopMatrix();
            render_borders();

        glPopMatrix();
    }

    void view::do_render(float rel_x, float rel_y, bool clicking, bool sendclick, int lastx, int lasty) {
        if(sendclick) {
            if(press_reset) press_reset = false;
            else {
                if(hovering((float)lastx, (float)lasty)) {
                    if(click_action != nullptr) click_action(this, (float)lastx, (float)lasty, click_data);
                }

                if(has_hover_style) rendered_style = &hover_style;

                if(!was_hovering) {
                    was_hovering = true;
                    if(hover_action != nullptr) hover_action(this, rel_x, rel_y, hover_data);
                }
            }
        } else if(hovering(rel_x, rel_y)) {
            if(has_hover_style) rendered_style = &hover_style;

            if(!was_hovering) {
                was_hovering = true;
                if(hover_action != nullptr) hover_action(this, rel_x, rel_y, hover_data);
            }

            if(clicking) {
                if(has_active_style) rendered_style = &active_style;
            }
        } else {
            if(clicking) press_reset = true;

            rendered_style = &style;

            if(was_hovering) {

                was_hovering = false;
                if(leave_action != nullptr) leave_action(this, rel_x, rel_y, leave_data);

            }
        }

        // this is an awful solution, but I can't be bothered editing all the individual render functions right now
        // as such, it's fine and it'll do for now.
        // todo: change this later

        __rel_x = rel_x;
        __rel_y = rel_y;
        __clicking = clicking;
        __last_x = lastx;
        __last_y = lasty;
        __send_click = sendclick;

        render();
    }

    view* view::on_hover(std::function<void(view*, float, float, void*)> callback, void* data) {
        hover_action = callback;
        hover_data = data;
        return this;
    }

    view* view::on_leave(std::function<void(view*, float, float, void*)> callback, void* data) {
        leave_action = callback;
        leave_data = data;
        return this;
    }

    view* view::on_click(std::function<void(view*, float, float, void*)> callback, void* data) {
        click_action = callback;
        click_data = data;
        return this;
    }

    bool view::hovering(float rel_x, float rel_y) {
        // todo: do something about rounded borders here
        // todo: do something about rotation here
        return 
            rel_x >= rendered_style->offset_x + rendered_style->margin_left &&
            rel_x <= rendered_style->offset_x + get_width() - rendered_style->margin_right &&
            rel_y >= rendered_style->offset_y + rendered_style->margin_top &&
            rel_y <= rendered_style->offset_y + get_height() - rendered_style->margin_bottom;
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

    view* view::set_style(style_t s) {
        style = s;
        return this;
    }

    view* view::hover_offset(float x, float y) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.offset_x = x;
        hover_style.offset_y = y;
        return this;
    }

    view* view::hover_margin(float margin) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.margin_top = margin;
        hover_style.margin_right = margin;
        hover_style.margin_bottom = margin;
        hover_style.margin_left = margin;
        return this;
    }

    view* view::hover_margin(float vertical, float horizontal) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.margin_top = vertical;
        hover_style.margin_right = horizontal;
        hover_style.margin_bottom = vertical;
        hover_style.margin_left = horizontal;
        return this;
    }

    view* view::hover_margin(float top, float right, float bottom, float left) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.margin_top = top;
        hover_style.margin_right = right;
        hover_style.margin_bottom = bottom;
        hover_style.margin_left = left;
        return this;
    }

    view* view::hover_padding(float padding) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.padding_top = padding;
        hover_style.padding_right = padding;
        hover_style.padding_bottom = padding;
        hover_style.padding_left = padding;
        return this;
    }

    view* view::hover_padding(float vertical, float horizontal) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.padding_top = vertical;
        hover_style.padding_right = horizontal;
        hover_style.padding_bottom = vertical;
        hover_style.padding_left = horizontal;
        return this;
    }

    view* view::hover_padding(float top, float right, float bottom, float left) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.padding_top = top;
        hover_style.padding_right = right;
        hover_style.padding_bottom = bottom;
        hover_style.padding_left = left;
        return this;
    }

    view* view::hover_border(border_t border) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.border_top = border;
        hover_style.border_right = border;
        hover_style.border_bottom = border;
        hover_style.border_left = border;
        return this;
    }

    view* view::hover_border(border_t vertical, border_t horizontal) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.border_top = vertical;
        hover_style.border_right = horizontal;
        hover_style.border_bottom = vertical;
        hover_style.border_left = horizontal;
        return this;
    }

    view* view::hover_border(border_t top, border_t right, border_t bottom, border_t left) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.border_top = top;
        hover_style.border_right = right;
        hover_style.border_bottom = bottom;
        hover_style.border_left = left;
        return this;
    }

    view* view::hover_border_radius(float radius) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.border_top_left_radius = radius;
        hover_style.border_top_right_radius = radius;
        hover_style.border_bottom_right_radius = radius;
        hover_style.border_bottom_left_radius = radius;
        return this;
    }

    view* view::hover_border_radius(float top_left, float top_right, float bottom_right, float bottom_left) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.border_top_left_radius = top_left;
        hover_style.border_top_right_radius = top_right;
        hover_style.border_bottom_right_radius = bottom_right;
        hover_style.border_bottom_left_radius = bottom_left;
        return this;
    }

    view* view::hover_background_color(uint32_t color) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.background_color = color;
        return this;
    }

    view* view::hover_foreground_color(uint32_t color) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.color = color;
        return this;
    }

    view* view::hover_rotation(float degrees) {
        if(!has_hover_style) {
            has_hover_style = true;
            hover_style = style;
        }
        hover_style.rotation = degrees;
        return this;
    }

    view* view::active_offset(float x, float y) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.offset_x = x;
        active_style.offset_y = y;
        return this;
    }

    view* view::active_margin(float margin) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.margin_top = margin;
        active_style.margin_right = margin;
        active_style.margin_bottom = margin;
        active_style.margin_left = margin;
        return this;
    }

    view* view::active_margin(float vertical, float horizontal) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.margin_top = vertical;
        active_style.margin_right = horizontal;
        active_style.margin_bottom = vertical;
        active_style.margin_left = horizontal;
        return this;
    }

    view* view::active_margin(float top, float right, float bottom, float left) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.margin_top = top;
        active_style.margin_right = right;
        active_style.margin_bottom = bottom;
        active_style.margin_left = left;
        return this;
    }

    view* view::active_padding(float padding) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.padding_top = padding;
        active_style.padding_right = padding;
        active_style.padding_bottom = padding;
        active_style.padding_left = padding;
        return this;
    }

    view* view::active_padding(float vertical, float horizontal) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.padding_top = vertical;
        active_style.padding_right = horizontal;
        active_style.padding_bottom = vertical;
        active_style.padding_left = horizontal;
        return this;
    }

    view* view::active_padding(float top, float right, float bottom, float left) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.padding_top = top;
        active_style.padding_right = right;
        active_style.padding_bottom = bottom;
        active_style.padding_left = left;
        return this;
    }

    view* view::active_border(border_t border) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.border_top = border;
        active_style.border_right = border;
        active_style.border_bottom = border;
        active_style.border_left = border;
        return this;
    }

    view* view::active_border(border_t vertical, border_t horizontal) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.border_top = vertical;
        active_style.border_right = horizontal;
        active_style.border_bottom = vertical;
        active_style.border_left = horizontal;
        return this;
    }

    view* view::active_border(border_t top, border_t right, border_t bottom, border_t left) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.border_top = top;
        active_style.border_right = right;
        active_style.border_bottom = bottom;
        active_style.border_left = left;
        return this;
    }

    view* view::active_border_radius(float radius) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.border_top_left_radius = radius;
        active_style.border_top_right_radius = radius;
        active_style.border_bottom_right_radius = radius;
        active_style.border_bottom_left_radius = radius;
        return this;
    }

    view* view::active_border_radius(float top_left, float top_right, float bottom_right, float bottom_left) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.border_top_left_radius = top_left;
        active_style.border_top_right_radius = top_right;
        active_style.border_bottom_right_radius = bottom_right;
        active_style.border_bottom_left_radius = bottom_left;
        return this;
    }

    view* view::active_background_color(uint32_t color) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.background_color = color;
        return this;
    }

    view* view::active_foreground_color(uint32_t color) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.color = color;
        return this;
    }

    view* view::active_rotation(float degrees) {
        if(!has_active_style) {
            has_active_style = true;
            active_style = style;
        }
        active_style.rotation = degrees;
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

            glTranslatef(rendered_style->offset_x + rendered_style->margin_left,
                         rendered_style->offset_y + rendered_style->margin_top,
                         0.0f);
            glRotatef(rendered_style->rotation, 0.0f, 0.0f, 1.0f);

            float x_off = rendered_style->offset_x + rendered_style->margin_left;
            float y_off = rendered_style->offset_y + rendered_style->margin_top;

            float w = get_content_box_width();
            float h = get_content_box_height();

            render_background();

            glPushMatrix();

                glTranslatef(rendered_style->border_left.stroke + rendered_style->padding_left,
                             rendered_style->border_top.stroke + rendered_style->padding_top,
                             0.0f);

                x_off += rendered_style->border_left.stroke + rendered_style->padding_left;
                y_off += rendered_style->border_top.stroke + rendered_style->padding_top;

                float x_offset = 0.0f,
                      y_offset = 0.0f,
                      z_offset = 0.0f;

                for(view* v : content) {
                    
                    int h_alignment = 0;
                    int v_alignment = 0;

                    float cur_x_offset = 0.0f;
                    float cur_y_offset = 0.0f;

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

                    if(style.alignment != alignment_t::top_leading) {
                        glPushMatrix();

                            glTranslatef(
                                (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w),
                                (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h),
                                0.0f
                            );

                            cur_x_offset += (h_alignment == 0) ? 0 : ((h_alignment == 1) ? (w / 2) : w);
                            cur_y_offset += (v_alignment == 0) ? 0 : ((v_alignment == 1) ? (h / 2) : h);
                    }

                    float vw = v->get_width(),
                          vh = v->get_height();

                    glPushMatrix();

                        float x_alignment_offset = vw,
                              y_alignment_offset = vh;

                        if(dir == stack_direction::horizontal) x_alignment_offset = get_content_width();
                        if(dir == stack_direction::vertical)   y_alignment_offset = get_content_height();

                        if(h_alignment == 0) x_alignment_offset = 0;
                        if(h_alignment == 1) x_alignment_offset /= 2;

                        if(v_alignment == 0) y_alignment_offset = 0;
                        if(v_alignment == 1) y_alignment_offset /= 2;

                        glTranslatef(
                            x_offset - x_alignment_offset,
                            y_offset - y_alignment_offset,
                            z_offset
                        );

                        cur_x_offset += x_offset - x_alignment_offset;
                        cur_y_offset += y_offset - y_alignment_offset;

                        v->do_render(
                            __rel_x - x_off - cur_x_offset,
                            __rel_y - y_off - cur_y_offset,
                            __clicking,
                            __send_click,
                            (int)(__last_x - x_off - cur_x_offset),
                            (int)(__last_y - y_off - cur_y_offset)
                        );

                    glPopMatrix();

                    if(style.alignment != alignment_t::top_leading) {
                        glPopMatrix();
                    }

                    switch(dir) {
                        case stack_direction::horizontal: { x_offset += vw; break; }
                        case stack_direction::vertical:   { y_offset += vh; break; }
                        case stack_direction::depth:                        break;
                    }
                }

            glPopMatrix();

            render_borders();

        glPopMatrix();
    }

}
