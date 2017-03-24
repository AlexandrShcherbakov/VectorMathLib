#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

namespace VM {
    constexpr float VEC_EPS = 1e-9;

    using uint = unsigned;

    template<typename T>
    constexpr inline T sqr(const T& value) {
        return value * value;
    }
}

#endif // MAIN_H_INCLUDED
