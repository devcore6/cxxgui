#include <cxxgui/cxxgui.hpp>

namespace cxxgui {
    void text::init() {
        view::init();

        if(!has_font) return;

        if(cur_fonts.size() == 0) {
            for(size_t i = 0; i < style.font_family.size(); i++) {
                bool font_exists = false;

                font_t* right_family = nullptr;

                for(auto& f : fonts)
                    if(f.family == style.font_family[i] && f.weight == style.font_weight && f.italic == style.italic) {
                        font_exists = true;
                        
                        if(f.size == style.font_size)
                            cur_fonts.push_back(&f);
                        else if(!right_family)
                            right_family = &f;

                        break;
                    }

                if(right_family != nullptr) {
                    font_t* cur = try_load_font_from_path(style.font_family[i], style.font_size, style.font_weight, style.italic, right_family->path);

                    if(cur != nullptr) {
                        cur_fonts.push_back(cur);
                        continue;
                    }
                }

                if(font_exists) continue;

                font_t* cur = try_load_font(style.font_family[i], style.font_size, style.font_weight, style.italic);

                if(cur != nullptr) cur_fonts.push_back(cur);
            }

            if(cur_fonts.size() == 0) {
                has_font = false;
                return;
            }
        }

        // todo: do something to use the backup fonts for characters that are missing in the primary font. This will probably require us to switch away from SDL2_TTF and instead make our own TTF parsing library, this is fine, but not happening any time soon.

        if(texture_id == 0) {
            SDL_Surface* surface = TTF_RenderUTF8_Blended(
                cur_fonts[0]->font,
                t.c_str(),
                uint32_t_to_sdl_color(style.color)
            );

            if(!surface) {
                // Something went wrong
                has_font = false;
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

            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

            glBindTexture(GL_TEXTURE_2D, 0);

            width = surface->w;
            height = surface->h;

            SDL_FreeSurface(surface);
        }
    }

    float text::get_content_width() { return width; }
    float text::get_content_height() { return height; }

    void text::render() {
        render_background();

        glPushMatrix();

            glTranslatef(style.border_left + style.padding_left,
                         style.border_top + style.padding_top,
                         0.0f);

            if(has_font) {

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

            }

        glPopMatrix();

        render_borders();
    }
}
