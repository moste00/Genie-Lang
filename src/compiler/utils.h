#pragma once

namespace genie {
    template<typename T>
    struct False {
        static constexpr bool value = false;
    };

    template<typename T, long n>
    //A finite stack of size n behaves as a normal stack as long as you push_shift at most n items to it
    //Once you push the (n+1)th element, however, the oldest element (the one at the bottom of the stack)
    //Is discarded and the entire stack is shifted by 1 to allow the new item at the top
    struct FiniteStack {
        static_assert(n >= 1, "FiniteStack must have positive size");

        T first;
        FiniteStack<T, n - 1> rest;

        inline constexpr void push_shift(const T& value) {
            rest.push_shift(first);
            first = value;
        }
    };
    template<typename T>
    struct FiniteStack<T, 0> {
        inline constexpr void push_shift(const T& value) { /*discard the value*/ }
    };


    template<typename T, long n, long i>
    struct FiniteStackGetter {
        static constexpr inline T from(FiniteStack<T, n> s) {
            static_assert(i < n, "FiniteStack index out of bound");
            return FiniteStackGetter<T, n - 1, i - 1>::from(s.rest);
        }
    };
    template<typename T, long n>
    struct FiniteStackGetter<T, n, 0> {
        static constexpr inline T from(FiniteStack<T, n> s) {
            return s.first;
        }
    };
}