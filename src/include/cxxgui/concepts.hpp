#pragma once

// Apple Clang and Xcode still have some issues with concepts
namespace std {
    template<class T>
    concept integral = is_integral_v<T>;

    template<class T>
    concept floating_point = is_floating_point_v<T>;
    
    namespace helper {
        template<class T, class U>
        concept same_helper = is_same_v<T, U>;
    }

    template<class T, class U>
    concept same_as = helper::same_helper<T, U> && helper::same_helper<U, T>;
}
