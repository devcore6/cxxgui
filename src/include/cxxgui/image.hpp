#pragma once

namespace cxxgui {
	class image : public view {
    private:
        std::string path = "";
        GLuint texture_id = 0;
        float width = 0;
        float height = 0;
        bool is_resizable = false;

    protected:
        float get_content_width();
        float get_content_height();
        void render();

    public:
        image(const char* p) : path(p) { }

        image* resizable(bool can_resize);

	};
}
