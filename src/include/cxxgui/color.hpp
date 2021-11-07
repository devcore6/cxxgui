#pragma once

namespace cxxgui {
    
    namespace color {

        // Shades of white to black
        constexpr uint32_t clear            = 0x00000000;
        constexpr uint32_t full_black       = 0x000000FF;
        constexpr uint32_t black            = 0x101010FF;
        constexpr uint32_t dark_gray        = 0x424245FF;
        constexpr uint32_t gray             = 0x979799FF;
        constexpr uint32_t light_gray       = 0xD5D7D8FF;
        constexpr uint32_t white            = 0xFFFFFFFF;

        // Shades of red
        constexpr uint32_t red              = 0xFF3037FF;
        constexpr uint32_t crimson          = 0xDC143CFF;
        constexpr uint32_t rusty_red        = 0xDA2C43FF;
        constexpr uint32_t rosewood         = 0x65000BFF;
        constexpr uint32_t redwood          = 0xA45953FF;
        constexpr uint32_t vermillion       = 0xE34234FF;
        constexpr uint32_t blood_red        = 0x660000FF;
        constexpr uint32_t scarlet          = 0xFF2400FF;
        constexpr uint32_t ruby             = 0x9B111EFF;

        // Shades of green
        constexpr uint32_t green            = 0x03A10EFF;
        constexpr uint32_t dark_green       = 0x006400FF;
        constexpr uint32_t evergreen        = 0x05472AFF;
        constexpr uint32_t jungle_green     = 0x29AB87FF;
        constexpr uint32_t emerald          = 0x50C878FF;
        constexpr uint32_t mint             = 0xAAF0D1FF;
        constexpr uint32_t sea_green        = 0x2E8B57FF;
        constexpr uint32_t lime             = 0x32CD32FF;

        // Shades of blue
        constexpr uint32_t blue             = 0x0071E3FF;
        constexpr uint32_t cyan             = 0x00FFAAFF;
        constexpr uint32_t teal             = 0x00C2BBFF;
        constexpr uint32_t ultramarine      = 0x4000FFFF;
        constexpr uint32_t savoy_blue       = 0x4B61D1FF;
        constexpr uint32_t navy_blue        = 0x000080FF;
        constexpr uint32_t midnight_blue    = 0x191970FF;
        constexpr uint32_t powder_blue      = 0xB0E0E6FF;
        constexpr uint32_t sapphire         = 0x082567FF;
        constexpr uint32_t indigo           = 0x4B0082FF;

        // Shades of purple
        constexpr uint32_t purple           = 0xF14BF1FF;
        constexpr uint32_t royal_purple     = 0x7851A9FF;
        constexpr uint32_t mauve            = 0xE0B0FFFF;
        constexpr uint32_t mulberry         = 0xC54B8CFF;
        constexpr uint32_t eminence         = 0x6C3082FF;
        constexpr uint32_t byzantium        = 0x702963FF;

        // Shades of brown
        constexpr uint32_t brown            = 0x4E3423FF;
        constexpr uint32_t rosy_brown       = 0xBC8F8FFF;
        constexpr uint32_t burnt_umber      = 0x8A3324FF;
        constexpr uint32_t chestnut         = 0x954535FF;
        constexpr uint32_t desert_sand      = 0xEDC9AFFF;
        constexpr uint32_t walnut           = 0x5C5248FF;
        constexpr uint32_t tan              = 0xD2B48CFF;
        constexpr uint32_t khaki            = 0xC3B091FF;

        // Shades of orange
        constexpr uint32_t orange           = 0xF56300FF;
        constexpr uint32_t safety_orange    = 0xFF7900FF;
        constexpr uint32_t peach            = 0xFFE5B4FF;
        constexpr uint32_t tangerine        = 0xFF9966FF;
        constexpr uint32_t orange_peel      = 0xFF9F00FF;
        constexpr uint32_t saffron          = 0xF4C430FF;

        // Shades of pink
        constexpr uint32_t pink             = 0xF24B9EFF;
        constexpr uint32_t hot_pink         = 0xFF69B4FF;
        constexpr uint32_t champagne_pink   = 0xF1DDCFFF;
        constexpr uint32_t baby_pink        = 0xF4C2C2FF;
        constexpr uint32_t lavender_pink    = 0xFBAED2FF;
        constexpr uint32_t american_pink    = 0xFF9899FF;
        constexpr uint32_t coral_pink       = 0xF88379FF;
        constexpr uint32_t bright_pink      = 0xFB607FFF;

        // Shades of yellow
        constexpr uint32_t yellow           = 0xAD8200FF;
        constexpr uint32_t lemon_yellow     = 0xFDFF00FF;
        constexpr uint32_t royal_yellow     = 0xFADA5EFF;
        constexpr uint32_t safety_yellow    = 0xEED202FF;
        constexpr uint32_t chartreuse       = 0xDFFF00FF;
        constexpr uint32_t olive            = 0x808000FF;

        extern uint32_t foreground();
        extern uint32_t background();

    }

}
