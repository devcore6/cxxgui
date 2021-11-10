#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class symbols_page_1 : public view {
public:
    symbols_page_1() {
        body = new vstack{
            new hstack {
                new vstack {
                    new hstack {
                        (new image("../cxxgui.png"))
                            ->resizable(true)
                            ->frame(0, 544, 0, 0, 272, 0, alignment_t::center),
                        (new text("Symbols"))
                            ->font_weight(100)
                            ->font_size(100)
                    },
                    new hstack {
                        (new text("thin"))
                            ->font_weight(100)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("extralight"))
                            ->font_weight(200)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("light"))
                            ->font_weight(300)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("regular"))
                            ->font_weight(400)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("medium"))
                            ->font_weight(500)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("semibold"))
                            ->font_weight(600)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("bold"))
                            ->font_weight(700)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("extrabold"))
                            ->font_weight(800)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("black"))
                            ->font_weight(900)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("fill"))
                            ->font_weight(900)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center)
                    },
                    new hstack {
                        symbols::divide_2_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::divide_2_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::divide_2_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::divide_2()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::divide_2_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::divide_2_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::divide_2_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::divide_2_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::divide_2_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::divide_2_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::divide_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::divide_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::divide_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::divide_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::divide_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::divide_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::divide_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::divide_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::divide_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::divide_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::divide_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::divide_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::divide_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::divide()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::divide_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::divide_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::divide_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::divide_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::divide_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::divide_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::minus_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::minus_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::minus_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::minus_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::minus_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::minus_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::minus_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::minus_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::minus_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::minus_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::minus_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::minus_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::minus_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::minus()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::minus_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::minus_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::minus_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::minus_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::minus_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::minus_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::multiply_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::multiply_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::multiply_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::multiply_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::multiply_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::multiply_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::multiply_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::multiply_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::multiply_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::multiply_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::multiply_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::multiply_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::multiply_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::multiply()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::multiply_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::multiply_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::multiply_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::multiply_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::multiply_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::mulyiply_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    }
                },

                new vstack {
                    new hstack {    
                        (new text("thin"))
                            ->font_weight(100)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("extralight"))
                            ->font_weight(200)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("light"))
                            ->font_weight(300)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("regular"))
                            ->font_weight(400)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("medium"))
                            ->font_weight(500)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("semibold"))
                            ->font_weight(600)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("bold"))
                            ->font_weight(700)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("extrabold"))
                            ->font_weight(800)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("black"))
                            ->font_weight(900)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center),
                        (new text("fill"))
                            ->font_weight(900)
                            ->frame(92.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, alignment_t::center)
                    },
                    new hstack {
                        symbols::percent_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::percent_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::percent_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::percent()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::percent_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::percent_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::percent_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::percent_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::percent_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::percent_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::plus_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::plus_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::plus_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::plus_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::plus_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::plus_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::plus_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::plus_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::plus_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::plus_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::plus_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::plus_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::plus_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::plus()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::plus_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::plus_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::plus_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::plus_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::plus_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::plus_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::checkmark_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::checkmark_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::checkmark_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::checkmark_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::checkmark_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::checkmark_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::checkmark_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::checkmark_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::checkmark_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::checkmark_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::checkmark_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::checkmark_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::checkmark_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::checkmark()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::checkmark_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::checkmark_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::checkmark_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::checkmark_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::checkmark_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::checkmark_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::circle_inset_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::circle_inset_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::circle_inset_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::circle_inset()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::circle_inset_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::circle_inset_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::circle_inset_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::circle_inset_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::circle_inset_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::circle_inset_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::cross_circle_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::cross_circle_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::cross_circle_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::cross_circle()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::cross_circle_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::cross_circle_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::cross_circle_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::cross_circle_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::cross_circle_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::cross_circle_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack {
                        symbols::cross_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::cross_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::cross_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::cross()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::cross_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::cross_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::cross_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::cross_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::cross_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::cross_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    },

                    new hstack  {
                        symbols::warning_thin()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::red)
                            ->size(92),
                        symbols::warning_extralight()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::green)
                            ->size(92),
                        symbols::warning_light()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::blue)
                            ->size(92),
                        symbols::warning()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::purple)
                            ->size(92),
                        symbols::warning_medium()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::brown)
                            ->size(92),
                        symbols::warning_semibold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::orange)
                            ->size(92),
                        symbols::warning_bold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::pink)
                            ->size(92),
                        symbols::warning_extrabold()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::yellow)
                            ->size(92),
                        symbols::warning_black()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->secondary_color(color::jungle_green)
                            ->size(92),
                        symbols::warning_fill()
                            ->symbol_rendering_mode(symbol_rendering_modes::palette)
                            ->primary_color(color::white)
                            ->size(92)
                    }
                }
            }
        };
    }
};

int main(int argc, char* argv[]) {

    window_t window = window_t(
        "CXXGUI Test",
        200,
        200,
        1280,
        720,
        SDL_WINDOW_SHOWN,
        new symbols_page_1,
        [](SDL_Event e) {}
    );

    return 0;
}
