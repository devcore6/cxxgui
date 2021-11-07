#pragma once

namespace cxxgui {
    
    namespace color {

        constexpr uint32_t black  	= 0x101010FF;
        constexpr uint32_t blue  	= 0x0071E3FF;
        constexpr uint32_t brown  	= 0x4E3423FF;
        constexpr uint32_t clear  	= 0x00000000;
        constexpr uint32_t cyan  	= 0x00FFAAFF;
        constexpr uint32_t darkgray = 0x424245FF;
        constexpr uint32_t gray  	= 0xF5F5F7FF;
        constexpr uint32_t green  	= 0x03A10EFF;
        constexpr uint32_t indigo  	= 0x4B0082FF;
        constexpr uint32_t mint  	= 0xAAF0D1FF;
        constexpr uint32_t orange  	= 0xF56300FF;
        constexpr uint32_t pink  	= 0xF24B9EFF;
        constexpr uint32_t purple  	= 0xF14BF1FF;
        constexpr uint32_t red  	= 0xFF3037FF;
        constexpr uint32_t teal  	= 0x00C2BBFF;
        constexpr uint32_t white  	= 0xFFFFFFFF;
        constexpr uint32_t yellow  	= 0xAD8200FF;

        extern uint32_t foreground();
        extern uint32_t background();

    }

}
