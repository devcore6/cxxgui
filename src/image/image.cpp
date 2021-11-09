#include <cxxgui/cxxgui.hpp>

#if defined(_WIN32) || defined(_WIN64)
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
#endif

namespace cxxgui {
	float image::get_content_width() {
        float rendered_width = width;

        if(is_resizable) {
            if(style.width != 0.0f) rendered_width = style.width;
            if(rendered_width < style.min_width) rendered_width = style.min_width;
            if(style.max_width != 0.0f && rendered_width > style.max_width)
                rendered_width = style.max_width;
        } else {
            // preserve aspect ratio or something here
        }

        return rendered_width;
    }

	float image::get_content_height() {
        float rendered_height = height;

        if(is_resizable) {
            if(style.height != 0.0f) rendered_height = style.height;
            if(rendered_height < style.min_height) rendered_height = style.min_height;
            if(style.max_height != 0.0f && rendered_height > style.max_height)
                rendered_height = style.max_height;
        } else {
            // preserve aspect ratio or something here
        }

        return rendered_height;
    }

	void image::render() {
		if(path != "") {
			if(texture_id == 0) {
				SDL_Surface* surface = IMG_Load(path.c_str());
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
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

                glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

#if defined(_WIN32) || defined(_WIN64)
                if(!glGenerateMipmap) glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
                if(glGenerateMipmap) glGenerateMipmap(GL_TEXTURE_2D);
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

                        float rendered_width  = get_content_width();
                        float rendered_height = get_content_height();

                        float x_alignment_offset = rendered_width  + style.padding_left + style.padding_right,
                              y_alignment_offset = rendered_height + style.padding_top  + style.padding_bottom;

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

                            float width_percentage = 1.0f;
                            float height_percentage = 1.0f;

                            glBegin(GL_QUADS);

                                glTexCoord2f(0.0f, 0.0f);
                                glVertex2f(0.0f, 0.0f);

                                glTexCoord2f(width_percentage, 0.0f);
                                glVertex2f(rendered_width, 0.0f);

                                glTexCoord2f(width_percentage, height_percentage);
                                glVertex2f(rendered_width, rendered_height);

                                glTexCoord2f(0.0f, height_percentage);
                                glVertex2f(0.0f, rendered_height);

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

	image* image::resizable(bool can_resize) {
		is_resizable = can_resize;
		return this;
	}

}
