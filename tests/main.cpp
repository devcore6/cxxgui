#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class symbols_page_ui_base : public view {
public:
    symbols_page_ui_base() {
        body = new vstack {
            (new text("ui_base"))->font(title),

            new hstack {
                symbols::action_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::action_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::bolt_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bolt_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::checkmark_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::checkmark_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::checkmark_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::cross_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::cross_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::cross_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::eject_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::eject_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::folder_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::folder_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::warning_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::warning_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            }
        };
    }
};

class symbols_page_ui_connectivity : public view {
public:
    symbols_page_ui_connectivity() {
        body = new vstack {
            (new text("ui_connectivity"))->font(title),

            new hstack {
                symbols::bluetooth_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::bluetooth_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::wifi_1_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_1_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::wifi_2_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_2_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::wifi_3_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::wifi_3_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            }
        };
    }
};

class symbols_page_ui_input : public view {
public:
    symbols_page_ui_input() {
        body = new vstack {
            (new text("ui_input"))->font(title),

            new hstack {
                symbols::slider_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::slider_frame_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::stepper_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::stepper_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::toggle_circle_checkmark_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_circle_cross_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::toggle_frame_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            }
        };
    }
};

class symbols_page_ui_shapes : public view {
public:
    symbols_page_ui_shapes() {
        body = new vstack {
            (new text("ui_shapes"))->font(title),

            new hstack {
                symbols::circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_inset_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::square_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_inset_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            },

            new hstack {
                symbols::square_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                symbols::square_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
            }
        };
    }
};

class symbols_page_math : public view {
public:
    symbols_page_math() {
        body = new vstack {
            (new text("math"))->font(title),

            new hstack {
                new vstack {
                    new hstack {
                        symbols::divide_2_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::divide_2_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_2_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::divide_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::divide_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::divide_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::minus_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::minus_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::minus_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    }
                },

                new vstack {
                    new hstack {
                        symbols::multiply_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::multiply_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::multiply_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::percent_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::percent_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::percent_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::plus_circle_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_circle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::plus_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::plus_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    }
                }
            }
        };
    }
};

class symbols_page_media_controls : public view {
public:
    symbols_page_media_controls() {
        body = new vstack {
            (new text("media_controls"))->font(title),
            new hstack {
                new vstack {
                    new hstack {
                        symbols::backward_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::backward_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::forward_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::forward_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::pause_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::pause_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::play_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::play_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::record_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::record_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::repeat_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    }
                },

                new vstack {

                    new hstack {
                        symbols::repeat_one_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::repeat_one_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::shuffle_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::shuffle_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::stop_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::stop_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::volume_0_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_0_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::volume_1_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_1_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    },

                    new hstack {
                        symbols::volume_2_fill()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_thin()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_extralight()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_light()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_medium()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_semibold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_bold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_extrabold()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan),
                        symbols::volume_2_black()->size(92)->symbol_rendering_mode(symbol_rendering_modes::palette)->primary_color(color::white)->tertiary_color(color::cyan)
                    }
                }
            }
        };
    }
};

class content_view;

content_view* main_view = nullptr;

class content_view : public view {
private:
    int page = 0;
    bool scheduled_update = true;

    view* content = nullptr;

protected:
    void render() {
        if(scheduled_update) {
            if(body) delete body;

            switch(page) {
                default:
                case 0: content = new symbols_page_ui_base;         break;
                case 1: content = new symbols_page_ui_connectivity; break;
                case 2: content = new symbols_page_ui_input;        break;
                case 3: content = new symbols_page_ui_shapes;       break;
                case 4: content = new symbols_page_math;            break;
                case 5: content = new symbols_page_media_controls;  break;
            }

            body = new vstack {
                new hstack {
                    (new image("../cxxgui.png"))
                        ->resizable(true)
                        ->frame(0, 544, 0, 0, 272, 0, alignment_t::center),
                    (new text("Symbols"))
                        ->font_weight(100)
                        ->font_size(100)
                },
                new hstack {
                    new text(std::string("Page ") + std::to_string(page + 1)),
                    new stepper<int>(400, update_view, 0, 5, page)
                },
                content
            };
            
            scheduled_update = false;
        }

        view::render();
    }
public:

    static void update_view(view* v, int p) {
        main_view->page = p;
        main_view->scheduled_update = true;
    }
};

#include <thread>

int main(int argc, char* argv[]) {

    main_view = new content_view;

    window_t window = window_t(
        "CXXGUI Test",
        1280,
        720,
        main_view
    );

    return 0;
}
