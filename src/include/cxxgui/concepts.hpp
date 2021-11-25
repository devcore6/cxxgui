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

    template<class T, class U>
    concept convertible_to = is_convertible_v<T, U> && requires {
        static_cast<U>(declval<T>());
    };

    template<class T>
    concept boolean-testable = convertible_to<T, bool>;

    template<class T, class U>
    concept __PartiallyOrderedWith = requires(
        const std::remove_reference_t<T>& t,
        const std::remove_reference_t<U>& u
    ) {
        { t <  u } -> boolean-testable;
        { t >  u } -> boolean-testable;
        { t <= u } -> boolean-testable;
        { t >= u } -> boolean-testable;
        { u <  t } -> boolean-testable;
        { u >  t } -> boolean-testable;
        { u <= t } -> boolean-testable;
        { u >= t } -> boolean-testable;
    };

    template<class T>
    concept totally_ordered = equality_comparable<T> && __PartiallyOrderedWith<T, T>;

    template<class T>
    concept default_initializable = std::constructible_from<T> && requires {
        T{};
    } && requires {
        ::new (static_cast<void*>(nullptr)) T;
    };
}
