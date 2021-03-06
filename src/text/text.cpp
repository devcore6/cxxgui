#include <string>
#include <vector>
#include <initializer_list>
#include <functional>
#include <iomanip>
#include <sstream>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include <cxxgui/utilities.hpp>
#include <cxxgui/color.hpp>
#include <cxxgui/style.hpp>
#include <cxxgui/view.hpp>
#include <cxxgui/font.hpp>
#include <cxxgui/text.hpp>

namespace cxxgui {
    float text::get_content_width() { return width; }
    float text::get_content_height() { return height; }

    void text::render() {
        if(internal_font) {
            if(!texture_id) {
                std::vector<std::string> data = split_str(t, std::string("\n"));
                texture_count = data.size();

                texture_id = new GLuint[texture_count];
                widths = new int[texture_count];
                heights = new int[texture_count];

                glGenTextures((int)texture_count, texture_id);

                for(size_t i = 0; i < data.size(); i++) {
                    std::string str = data[i];

                    SDL_Surface* surface;
                    if(rendered_style->max_width == 0.0f)
                        surface = TTF_RenderUTF8_Blended(
                            internal_font->font,
                            str.c_str(),
                            uint32_t_to_sdl_color(0xFFFFFFFF)
                        );
                    else
                        surface = TTF_RenderUTF8_Blended_Wrapped(
                            internal_font->font,
                            str.c_str(),
                            uint32_t_to_sdl_color(0xFFFFFFFF),
                            (uint32_t)rendered_style->max_width
                        );

                    if(surface) {
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

                        glBindTexture(GL_TEXTURE_2D, texture_id[i]);

                        glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

                        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

                        glBindTexture(GL_TEXTURE_2D, 0);

                        if((float)surface->w > width) width = (float)surface->w;
                        widths[i] = surface->w;
                        heights[i] = surface->h;

                        SDL_FreeSurface(surface);
                    }
                }
                
                height = 0.0f;
                for(size_t i = 0; i < texture_count - 1; i++)
                    height += rendered_style->line_height * heights[i];
                height += heights[texture_count - 1];
            }

            if(texture_id) {
                glPushMatrix();

                    glTranslatef(rendered_style->offset_x + rendered_style->margin_left,
                                 rendered_style->offset_y + rendered_style->margin_top,
                                 0.0f);
                    glRotatef(rendered_style->rotation, 0.0f, 0.0f, 1.0f);

                    float w = get_content_box_width();
                    float h = get_content_box_height();

                    render_background();
                    glPushMatrix();

                        glTranslatef(rendered_style->border_left.stroke + rendered_style->padding_left,
                                     rendered_style->border_top.stroke + rendered_style->padding_top,
                                     0.0f);

                        int h_alignment = 0;
                        int v_alignment = 0;

                        switch(rendered_style->alignment) {
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

                        float x_alignment_offset = width + rendered_style->padding_left + rendered_style->padding_right,
                              y_alignment_offset = height + rendered_style->padding_top + rendered_style->padding_bottom;

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

                            glColor4f(
                                ((rendered_style->color >> 24) & 0xFF) / 255.0f,
                                ((rendered_style->color >> 16) & 0xFF) / 255.0f,
                                ((rendered_style->color >>  8) & 0xFF) / 255.0f,
                                ( rendered_style->color        & 0xFF) / 255.0f
                            );

                            // todo: text alignment
                            float cur_height = 0.0f;
                            for(size_t i = 0; i < texture_count; i++) {
                                glBindTexture(GL_TEXTURE_2D, texture_id[i]);

                                glBegin(GL_QUADS);

                                    glTexCoord2f(0.0f, 0.0f);
                                    glVertex2f(0.0f, cur_height);

                                    glTexCoord2f(1.0f, 0.0f);
                                    glVertex2f((float)widths[i], cur_height);

                                    glTexCoord2f(1.0f, 1.0f);
                                    glVertex2f((float)widths[i], heights[i] + cur_height);

                                    glTexCoord2f(0.0f, 1.0f);
                                    glVertex2f(0.0f, heights[i] + cur_height);

                                glEnd();

                                cur_height += heights[i] * rendered_style->line_height;
                            }

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

    text* text::set_text(const char* str) {
        t = str;
        if(texture_id != nullptr) {
            glDeleteTextures((int)texture_count, texture_id);
            delete[] texture_id;
            delete[] widths;
            delete[] heights;
            texture_id = nullptr;
            widths = heights = nullptr;
        }
        return this;
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
