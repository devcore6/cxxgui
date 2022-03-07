#include <string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <iomanip>
#include <functional>

#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

#include <cxxgui/utilities.hpp>
#include <cxxgui/color.hpp>
#include <cxxgui/style.hpp>
#include <cxxgui/view.hpp>
#include <cxxgui/symbols.hpp>

namespace cxxgui {

    float symbol::get_content_width() {
        float rendered_width = 32.0f;

        if(style.height != 0.0f) rendered_width = style.width;
        if(rendered_width < style.min_height) rendered_width = style.min_width;
        if(style.max_width != 0.0f && rendered_width > style.max_width)
            rendered_width = style.max_width;

        return rendered_width;
    }

    float symbol::get_content_height() {
        float rendered_height = 32.0f;

        if(style.height != 0.0f) rendered_height = style.height;
        if(rendered_height < style.min_height) rendered_height = style.min_height;
        if(style.max_height != 0.0f && rendered_height > style.max_height)
            rendered_height = style.max_height;

        return rendered_height;
    }

    // note: SVGs don't support alpha colors in SDL_image
    //       as such, I will probably have to fix it later
    //       with a different library

    void symbol::render() {
        if(texture_id == 0) {
            if(render_mode == symbol_rendering_modes::monochrome) {
                color2 = color1;
                color3 = color1;
                color4 = color1;
                color5 = color1;
            }

            if(render_mode == symbol_rendering_modes::hierarchical) {
                color2 = ((uint32_t)(((color1 >> 24) & 0xFF) * 0.6f)) << 24 |
                         ((uint32_t)(((color1 >> 16) & 0xFF) * 0.6f)) << 16 |
                         ((uint32_t)(((color1 >>  8) & 0xFF) * 0.6f)) <<  8 |
                         ((uint32_t)(( color1        & 0xFF) * 0.6f));
                color3 = ((uint32_t)(((color2 >> 24) & 0xFF) * 0.6f)) << 24 |
                         ((uint32_t)(((color2 >> 16) & 0xFF) * 0.6f)) << 16 |
                         ((uint32_t)(((color2 >>  8) & 0xFF) * 0.6f)) <<  8 |
                         ((uint32_t)(( color2        & 0xFF) * 0.6f));
                color4 = ((uint32_t)(((color3 >> 24) & 0xFF) * 0.6f)) << 24 |
                         ((uint32_t)(((color3 >> 16) & 0xFF) * 0.6f)) << 16 |
                         ((uint32_t)(((color3 >>  8) & 0xFF) * 0.6f)) <<  8 |
                         ((uint32_t)(( color3        & 0xFF) * 0.6f));
                color5 = ((uint32_t)(((color4 >> 24) & 0xFF) * 0.6f)) << 24 |
                         ((uint32_t)(((color4 >> 16) & 0xFF) * 0.6f)) << 16 |
                         ((uint32_t)(((color4 >>  8) & 0xFF) * 0.6f)) <<  8 |
                         ((uint32_t)(( color4        & 0xFF) * 0.6f));
            }

            /*
             * Warning: jank alert
             * Weak minds look away
             */

            float scale_factor = get_content_height() / 512.0f;

            size_t pos = std::string::npos;

            while((pos = svg_data.find("rgb(0,0,0)")) != std::string::npos) {
                svg_data.erase(pos, 10);
                svg_data.insert(
                    pos,
                    std::string("#") +
                    to_hex((color1 >> 24) & 0xFF) +
                    to_hex((color1 >> 16) & 0xFF) +
                    to_hex((color1 >> 8) & 0xFF)
                );
            }

            while((pos = svg_data.find("rgb(64,64,64)")) != std::string::npos) {
                svg_data.erase(pos, 13);
                svg_data.insert(
                    pos,
                    std::string("#") +
                    to_hex((color2 >> 24) & 0xFF) +
                    to_hex((color2 >> 16) & 0xFF) +
                    to_hex((color2 >> 8) & 0xFF)
                );
            }

            while((pos = svg_data.find("rgb(128,128,128)")) != std::string::npos) {
                svg_data.erase(pos, 16);
                svg_data.insert(
                    pos,
                    std::string("#") +
                    to_hex((color3 >> 24) & 0xFF) +
                    to_hex((color3 >> 16) & 0xFF) +
                    to_hex((color3 >> 8) & 0xFF)
                );
            }

            while((pos = svg_data.find("rgb(192,192,192)")) != std::string::npos) {
                svg_data.erase(pos, 16);
                svg_data.insert(
                    pos,
                    std::string("#") +
                    to_hex((color4 >> 24) & 0xFF) +
                    to_hex((color4 >> 16) & 0xFF) +
                    to_hex((color4 >> 8) & 0xFF)
                );
            }

            while((pos = svg_data.find("rgb(255,255,255)")) != std::string::npos) {
                svg_data.erase(pos, 16);
                svg_data.insert(
                    pos,
                    std::string("#") +
                    to_hex((color5 >> 24) & 0xFF) +
                    to_hex((color5 >> 16) & 0xFF) +
                    to_hex((color5 >> 8) & 0xFF)
                );
            }

            if(_weight != 16)
                while((pos = svg_data.find("stroke-width=\"16\"")) != std::string::npos) {
                    svg_data.erase(pos + 14, 2);
                    svg_data.insert(pos + 14, std::to_string(_weight));
                }

            svg_data = modify_numbers<float>(svg_data, [scale_factor](float i) -> float { return i * scale_factor; }, true, svg_data.find("viewBox"));

            SDL_RWops* mem = SDL_RWFromConstMem(svg_data.data(), (int)svg_data.size());
            if(!mem) return;

            SDL_Surface* surface = IMG_LoadSVG_RW(mem);

            SDL_RWclose(mem);
            if(!surface) return;

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

            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

            glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

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


                render_background();
                glPushMatrix();

                    glTranslatef(style.border_left.stroke + style.padding_left,
                                 style.border_top.stroke + style.padding_top,
                                 0.0f);

                    glEnable(GL_TEXTURE_2D);

                    // temporarily setting the alpha value in here
                    // as SDL_image doesn't support alpha in SVGs

                    glColor4f(1.0f, 1.0f, 1.0f, (color1 & 0xFF) / 255.0f);
                    glBindTexture(GL_TEXTURE_2D, texture_id);

                    // why is this scaling needed???

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

                render_borders();

            glPopMatrix();
        }
    }

}
