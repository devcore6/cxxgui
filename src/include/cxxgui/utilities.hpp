#pragma once

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

    template<typename T>
    concept numeric_type = std::integral<T> || std::floating_point<T>;

    template<numeric_type T>
    T clamp(T min, T val, T max) { return (val < min) ? min : ((val > max) ? max : val); }

    template<typename T>
    concept character_type = std::same_as<T, char> ||
                             std::same_as<T, signed char> ||
                             std::same_as<T, unsigned char> ||
                             std::same_as<T, wchar_t> ||
                             std::same_as<T, char8_t> ||
                             std::same_as<T, char16_t> ||
                             std::same_as<T, char32_t>;

    template<character_type T>
    std::basic_string<T> replace(std::basic_string<T>  str, std::basic_string<T>  to_replace, std::basic_string<T>  replace_with) {
        std::basic_string<T>  ret = str;

        size_t last_pos = 0;
        size_t pos = std::basic_string<T>::npos;

        while((pos = ret.find(to_replace, last_pos)) != std::basic_string<T>::npos) {
            ret = ret.replace(pos, to_replace.length(), replace_with);
            last_pos = pos - to_replace.length() + replace_with.length() + 1;
        }

        return ret;
    }
    
    template<character_type T>
    std::basic_string<T> replace_until(std::basic_string<T> str, std::basic_string<T> to_replace_start, std::basic_string<T> to_replace_end, std::basic_string<T> replace_with) {
        std::basic_string<T> ret = str;

        size_t last_pos = 0;
        size_t pos = std::basic_string<T>::npos;
        size_t end_pos = std::basic_string<T>::npos;

        while(
            ((pos = ret.find(to_replace_start, last_pos)) != std::basic_string<T>::npos) &&
            ((end_pos = ret.find(to_replace_end, pos + to_replace_start.length())) != std::basic_string<T>::npos)
            ) {
            ret = ret.replace(pos, end_pos - pos + to_replace_end.length(), replace_with);
            last_pos = pos - to_replace_start.length() + replace_with.length() + 1;
        }

        return ret;
    }

    template<numeric_type I>
    std::string modify_numbers(std::string str, std::function<I(I)> func, bool skip_colors = false, size_t start = 0) {
        std::string ret = str;

        I i = 0;

        bool sign = false;
        bool found_number = false;
        bool decimal = false;
        size_t decimal_factor = 10;
        size_t pos = start;
        size_t start_pos = 0;
        
        bool skipping = false;

        for(char c = ret[pos]; ret[pos]; ++pos, c = ret[pos]) {
            if(!found_number && c == '#' && skip_colors) { skipping = true; continue; }
            if(!found_number && c == '-') { sign = true; continue; }
            if(c == '.' && !decimal) { decimal = true; decimal_factor = 10; continue; }
            if(isdigit(c)) {
                if(!found_number) {
                    found_number = true;
                    start_pos = pos;
                }

                if(!decimal) {
                    i *= 10;
                    i += c - '0';
                } else {
                    i += (I)(c - '0') / decimal_factor;
                    decimal_factor *= 10;
                }

                continue;
            }

            if(skipping && ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) continue;

            if(found_number && !skipping) {
                size_t len = pos - start_pos;
                std::string s = std::to_string((long double)func(i));
                ret = ret.replace(start_pos, len, s);
                pos += s.length() - len;
            }

            i = 0;
            found_number = false;
            sign = false;
            decimal = false;
            skipping = false;
        }

        return ret;
    }

}
