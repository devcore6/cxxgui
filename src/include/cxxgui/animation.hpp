#pragma once

namespace cxxgui {

    extern float linear(float step, float pos);

    template<typename T>
    concept numeric_type = std::integral<T> || std::floating_point<T>;

    template<numeric_type T>
    T clamp(T min, T val, T max) { return (val < min) ? min : ((val > max) ? max : val); }

    template<size_t duration> requires(duration != 0)
    class animation {
    private:
        const float step = 1.0f / (float)duration;

        float state = 0.0f;

    public:
        std::function<float(float, float)> curve_function = linear;

        style_t start_value;
        style_t end_value;

        animation() { }

        style_t tick(size_t ticks) {
            style_t ret = start_value;

            if(state == 1.0f) return ret;

            state = clamp(0.0f, curve_function(step * ticks, state), 1.0f);

            ret.offset_x += (end_value.offset_x - ret.offset_x) * state;
            ret.offset_y += (end_value.offset_y - ret.offset_y) * state;
            ret.margin_top += (end_value.margin_top - ret.margin_top) * state;
            ret.margin_right += (end_value.margin_right - ret.margin_right) * state;
            ret.margin_left += (end_value.margin_left - ret.margin_left) * state;
            ret.margin_bottom += (end_value.margin_bottom - ret.margin_bottom) * state;
            ret.padding_top += (end_value.padding_top - ret.padding_top) * state;
            ret.padding_right += (end_value.padding_right - ret.padding_right) * state;
            ret.padding_left += (end_value.padding_left - ret.padding_left) * state;
            ret.padding_bottom += (end_value.padding_bottom - ret.padding_bottom) * state;
            ret.border_top.stroke += (end_value.border_top.stroke - ret.border_top.stroke) * state;
            ret.border_top.color += (uint32_t)((float)(end_value.border_top.color - ret.border_top.color) * state);
            ret.border_right.stroke += (end_value.border_right.stroke - ret.border_right.stroke) * state;
            ret.border_right.color += (uint32_t)((float)(end_value.border_right.color - ret.border_right.color) * state);
            ret.border_left.stroke += (end_value.border_left.stroke - ret.border_left.stroke) * state;
            ret.border_left.color += (uint32_t)((float)(end_value.border_left.color - ret.border_left.color) * state);
            ret.border_bottom.stroke += (end_value.border_bottom.stroke - ret.border_bottom.stroke) * state;
            ret.border_bottom.color += (uint32_t)((float)(end_value.border_bottom.color - ret.border_bottom.color) * state);
            ret.border_top_left_radius += (end_value.border_top_left_radius - ret.border_top_left_radius) * state;
            ret.border_top_right_radius += (end_value.border_top_right_radius - ret.border_top_right_radius) * state;
            ret.border_bottom_right_radius += (end_value.border_bottom_right_radius - ret.border_bottom_right_radius) * state;
            ret.border_bottom_left_radius += (end_value.border_bottom_left_radius - ret.border_bottom_left_radius) * state;
            ret.background_color += (uint32_t)((float)(end_value.background_color - ret.background_color) * state);
            ret.color += (uint32_t)((float)(end_value.color - ret.color) * state);
            ret.width += (end_value.width - ret.width) * state;
            ret.height += (end_value.height - ret.height) * state;
            ret.min_width += (end_value.min_width - ret.min_width) * state;
            ret.max_width += (end_value.max_width - ret.max_width) * state;
            ret.min_height += (end_value.min_height - ret.min_height) * state;
            ret.max_height += (end_value.max_height - ret.max_height) * state;
            ret.rotation += (end_value.rotation - ret.rotation) * state;

            return ret;
        }

        void reset() { state = 0.0f; }
        float get_state() { return state; }
    };

}
