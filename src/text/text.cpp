#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    float text::get_content_width() { return width; }
    float text::get_content_height() { return height; }

    void text::render() {
        if(internal_font) {
            if(texture_id == 0) {
                SDL_Surface* surface;
                if(style.max_width == 0.0f)
                    surface = TTF_RenderUTF8_Blended(
                        internal_font->font,
                        t.c_str(),
                        uint32_t_to_sdl_color(style.color)
                    );
                else
                    surface = TTF_RenderUTF8_Blended_Wrapped(
                        internal_font->font,
                        t.c_str(),
                        uint32_t_to_sdl_color(style.color),
                        (uint32_t)style.max_width
                    );

                if(!surface) {
                    return;
                }

                int mode = GL_RGB;
                if(surface->format->BytesPerPixel == 4) {
                    if(surface->format->Rmask == 0x000000ff)
                        mode = GL_RGBA;
                    else
                        mode = GL_BGRA;
                } else {
                    if(surface->format->Rmask == 0x000000ff)
                        mode = GL_RGB;
                    else
                        mode = GL_BGR;
                }

                glGenTextures(1, &texture_id);
                glBindTexture(GL_TEXTURE_2D, texture_id);

                glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

                glBindTexture(GL_TEXTURE_2D, 0);

                width = (float)surface->w;
                height = (float)surface->h;

                SDL_FreeSurface(surface);
            }

            if(texture_id != 0) {
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

                        float x_alignment_offset = width + style.padding_left + style.padding_right,
                              y_alignment_offset = height + style.padding_top + style.padding_bottom;

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

                            glEnable(GL_TEXTURE_2D);

                            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                            glBindTexture(GL_TEXTURE_2D, texture_id);

                            glBegin(GL_QUADS);

                                glTexCoord2f(0.0f, 0.0f);
                                glVertex2f(0.0f, 0.0f);

                                glTexCoord2f(1.0f, 0.0f);
                                glVertex2f(width, 0.0f);

                                glTexCoord2f(1.0f, 1.0f);
                                glVertex2f(width, height);

                                glTexCoord2f(0.0f, 1.0f);
                                glVertex2f(0.0f, height);

                            glEnd();

                            glBindTexture(GL_TEXTURE_2D, 0);

                            glDisable(GL_TEXTURE_2D);

                        glPopMatrix();

                        if(h_alignment != 0 || v_alignment != 0) {
                            glPopMatrix();
                        }

                    glPopMatrix();
                    render_borders();

                glPopMatrix();

            }

        }
    }

    text* text::font(font_t* f) {
        internal_font = f;
        return this;
    }

    text* text::toggle_italic() {
        internal_font = internal_font->toggle_italic();
        return this;
    }

    text* text::font_size(uint32_t s) {
        internal_font = internal_font->set_size(s);
        return this;
    }

    text* text::font_weight(uint16_t w) {
        internal_font = internal_font->set_weight(w);
        return this;
    }

    text* text::operator+=(text* rhs) {
        t += rhs->t;
        return this;
    }

    /*
     * Comparison
     */

    bool text::operator==(text* rhs) { return t == rhs->t; }
    bool text::operator!=(text* rhs) { return t != rhs->t; }

}
