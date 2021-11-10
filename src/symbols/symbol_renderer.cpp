#include <cxxgui/cxxgui.hpp>
#include <iomanip>
#include <sstream>

namespace cxxgui {

    template<typename T>
    std::string to_hex(T i) {
        std::stringstream stream;
        stream << std::setfill('0')
               << std::setw(2)
               << std::hex
               << i;
        return stream.str();
    }

    float symbol::get_content_width() {
        float rendered_width = 32.0f;

        if(style.width != 0.0f) rendered_width = style.width;
        if(rendered_width < style.min_width) rendered_width = style.min_width;
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

            /*
             * Warning: jank alert
             * Weak minds look away
             */

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

            SDL_RWops* mem = SDL_RWFromConstMem(svg_data.data(), (int)svg_data.capacity());
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
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

            glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

#if defined(_WIN32) || defined(_WIN64)
            ((PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap"))(GL_TEXTURE_2D);
#else
            glGenerateMipmap(GL_TEXTURE_2D);
#endif

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


                    float rendered_width  = get_content_width();
                    float rendered_height = get_content_height();

                    glEnable(GL_TEXTURE_2D);

                    // temporarily setting the alpha value in here
                    // as SDL_image doesn't support alpha in SVGs

                    glColor4f(1.0f, 1.0f, 1.0f, 255.0f / (color1 & 0xFF));
                    glBindTexture(GL_TEXTURE_2D, texture_id);

                    // why is this scaling needed???

                    glBegin(GL_QUADS);

                        glTexCoord2f(0.0f, 0.0f);
                        glVertex2f(0.0f, 0.0f);

                        glTexCoord2f(1.0f, 0.0f);
                        glVertex2f(rendered_width * 1.3334f, 0.0f);

                        glTexCoord2f(1.0f, 1.0f);
                        glVertex2f(rendered_width * 1.3334f, rendered_height * 1.3334f);

                        glTexCoord2f(0.0f, 1.0f);
                        glVertex2f(0.0f, rendered_height * 1.3334f);

                    glEnd();

                    glBindTexture(GL_TEXTURE_2D, 0);

                    glDisable(GL_TEXTURE_2D);

                glPopMatrix();

                render_borders();

            glPopMatrix();

        }
    }

}
