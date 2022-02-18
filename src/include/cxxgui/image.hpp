#pragma once

namespace cxxgui {
    class image;

    class shared_texture {
    protected:
        size_t* refcount = nullptr;
        GLsizei n = 1;
        GLuint* tex_id = nullptr;
        float* width = nullptr;
        float* height = nullptr;

        friend class image;

    public:
        shared_texture(GLsizei amount) :
            refcount(new size_t(1)),
            n(amount),
            tex_id(new GLuint[amount](0)),
            width(new float[amount](0.0f)),
            height(new float[amount](0.0f)) { glGenTextures(n, tex_id); }
        shared_texture(shared_texture& rhs) :
            refcount(rhs.refcount),
            n(rhs.n),
            tex_id(rhs.tex_id),
            width(rhs.width),
            height(rhs.height) { (*refcount)++; }
        ~shared_texture() { (*refcount)--; if(refcount == 0) glDeleteTextures(n, tex_id); delete refcount; delete[] tex_id; }
        void set_size(size_t i, float w, float h) { if(i > n) return; width[i] = w; height[i] = h; }
        float get_width(size_t i) { if(i > n) return 0.0f; return width[i]; }
        float get_height(size_t i) { if(i > n) return 0.0f; return height[i]; }
        GLuint operator[](size_t i) { if(i > n) return 0; return tex_id[i]; }
    };

	class image : public view {
    private:
        std::string path = "";
        GLuint texture_id = 0;
        float width = 0;
        float height = 0;
        bool is_resizable = false;
        bool should_free = true;
        size_t* refcount = nullptr;

    protected:
        float get_content_width();
        float get_content_height();
        void render();

    public:
        image(const char* p) : path(p) { }
        image(GLuint texid, float w, float h) : texture_id(texid), should_free(false), width(w), height(h) { }
        image(shared_texture texid, size_t n) :
            texture_id(texid[n]),
            width(texid.width[n]),
            height(texid.height[n]),
            should_free(false),
            refcount(texid.refcount) { (*refcount)++; }
        ~image() { if(texture_id != 0 && should_free) glDeleteTextures(1, &texture_id); if(refcount) *refcount--; }

        image* resizable(bool can_resize);

	};
}
