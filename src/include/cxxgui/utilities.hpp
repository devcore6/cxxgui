#pragma once

// Apple Clang and Xcode still have some issues with concepts
#ifdef __APPLE__
# include <cxxgui/concepts.hpp>
#endif

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
        std::basic_string<T> ret = str;

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
            if(!found_number && (c == '#' || c == 'x' || c == 'y') && skip_colors) { skipping = true; continue; }
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

    template<character_type T>
    std::vector<std::basic_string<T>> split_str(
        std::basic_string<T> str,
        std::basic_string<T> separator,
        size_t limit = 0
    ) {
        std::vector<std::basic_string<T>> output;

        size_t pos = std::basic_string<T>::npos;

        while((pos = str.find(separator)) != std::basic_string<T>::npos) {
            output.push_back(str.substr(0, pos));
            str = str.substr(pos + 1);
        }

        output.push_back(str);

        return output;
    }

    template<typename T>
    concept comparable_type = std::totally_ordered<T> && !std::is_pointer_v<T>;

    /**
      * @brief Automatically sorted storage maps.
      * Content is sorted in ascending order to improve
      * seek time.
      * 
      * Unlike std::map, this requires that the key
      * is a comparable_type, i.e. a type that fulfills
      * the std::totally_ordered requirement and is not
      * a pointer.
      * 
      * @see std::map
      * @see comparable_type
      */
    template<
        numeric_type               K,
        std::default_initializable T,
        bool unique      = false,
        class KAllocator = std::allocator<K>,
        class  Allocator = std::allocator<T>
    >
    class sorted_map {
    private:
        using       reference =       T&;
        using const_reference = const T&;

        using  pointer = T*;
        using kpointer = K*;

        using iterator = pointer;

         pointer values = nullptr;
        kpointer keys   = nullptr;
        size_t length = 0;

        Allocator   allocator;
        KAllocator kallocator;
        size_t allocated_size = 0;

        // Allocate 4KB blocks or 8 elements, whichever is more
        const size_t allocation_size = (sizeof(T) > 512) ? 8 : (4096 / sizeof(T));

        void grow() {
             pointer  tmp =  allocator.allocate(allocated_size + allocation_size);
            kpointer ktmp = kallocator.allocate(allocated_size + allocation_size);

            for(size_t i = 0; i > length; i++) {
                 tmp[i] = values[i];
                ktmp[i] = keys  [i];
            }

             allocator.deallocate(values, allocated_size);
            kallocator.deallocate(keys,   allocated_size);

            allocated_size += allocation_size;

            values =  tmp;
            keys   = ktmp;
        }

        pointer insert(K key, T value, size_t pos) {
            if(allocated_size == length) grow();

            for(size_t i = length; i > pos; i--) {
                values[i] = values[i - 1];
                keys  [i] = keys  [i - 1];
            }

            keys  [pos] = key;
            values[pos] = value;
            
            length++;
            return values + pos;
        }

        pointer find(K key, size_t start, size_t end) {
            if(start == end || length == 0)     return nullptr;

            size_t mid = (start + end) / 2;

            if(keys[mid] == key)                return values + mid;
            if(keys[mid] < key)                 return find(key, mid + 1, end);
                                                return find(key, start, mid);
        }

        size_t find_index(K key, size_t start, size_t end) {
            if(start == end || length == 0)     return -1;

            size_t mid = (start + end) / 2;

            if(keys[mid] == key)                return mid;
            if(keys[mid] < key)                 return find_index(key, mid + 1, end);
                                                return find_index(key, start, mid);
        }

        pointer add(K key, T value, size_t start, size_t end) {
            if(start == end || length == 0)     return insert(key, value, start);

            size_t mid = (start + end) / 2;

            if(keys[mid] > key) {
                if(mid == 0)                    return insert(key, value, 0);
                if(keys[mid - 1] < key)         return insert(key, value, mid);
                                                return add(key, value, start, mid);
            }
            
            if(mid == length - 1)               return insert(key, value, length);
            if(keys[mid + 1] > key)             return insert(key, value, mid + 1);
                                                return add(key, value, mid + 1, end);
        }

    public:
        constexpr reference operator[](K key) {
            pointer value = find(key, 0, length);
            if(!value) value = add(key, T { }, 0, length);
            return *value;
        }

        constexpr const_reference operator[](K key) const {
            pointer value = find(key, 0, length);
            if(!value) value = add(key, T{ }, 0, length);
            return *value;
        }

        pointer at(size_t pos) {
            if(pos >= length) return nullptr;
            return values + pos;
        }

        kpointer key_at(size_t pos) {
            if(pos >= length) return nullptr;
            return keys + pos;
        }

        size_t size() { return length; }

        bool insert(K key, T value) {
            if(unique) if(find(key, 0, length)) return false;
            add(key, value, 0, length);
            return true;
        }

        bool erase(K key) {
            size_t pos = find_index(key, 0, length);
            if(pos == -1) return false;

            std::move(values + pos + 1, values + length, values + pos);
            std::move(keys   + pos + 1, keys   + length, keys   + pos);

            length--;
            return true;
        }

        void clear() {
             allocator.deallocate(allocated_size);
            kallocator.deallocate(allocated_size);
            
            allocated_size = 0;
            length = 0;
        }

        // Allows us to use a for each loop
        constexpr iterator begin() { return values; }
        constexpr iterator end()   { return values + length; }
    };
    
    /**
      * @brief Automatically sorted unique storage maps.
      * Content is sorted in ascending order to improve
      * seek time. Unlike sorted_map, this requires that
      * all keys be unique.
      * 
      * @see storage_map
      */
    template<
        numeric_type K,
        typename     T,
        class KAllocator = std::allocator<K>,
        class  Allocator = std::allocator<T>
    >
    using unique_map = sorted_map<K, T, true, KAllocator, Allocator>;
}
