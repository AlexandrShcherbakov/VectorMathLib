#ifndef VECTOR4_H_INCLUDED
#define VECTOR4_H_INCLUDED

#include <iostream>

#include "vector3.h"

namespace VM {

template<typename T>
class vector4 {
public:
    const static uint Components = 4;

	///Coordinates
    T x, y, z, w;

    ///Constructors
    vector4(): x(T()), y(T()), z(T()), w(T()) {}
    vector4(const T x, const T y, const T z, const T w): x(x), y(y), z(z), w(w) {}
    vector4(const T val): x(val), y(val), z(val), w(val) {}
    vector4(const T* coords): x(coords[0]), y(coords[1]), z(coords[2]), w(coords[3]) {}
    vector4(const vector3<T>& v, const T w): x(v.x), y(v.y), z(v.z), w(w) {}
    template<typename U>
    vector4(const vector4<U>& v): x(v.x), y(v.y), z(v.z), w(v.w) {}

    ///Operators
    inline friend const vector4 operator+(const vector4 &v, const vector4 &w) {
        return vector4(v.x + w.x, v.y + w.y, v.z + w.z, v.w + w.w);
    }

    inline friend const vector4 operator-(const vector4 &v, const vector4 &w) {
        return vector4(v.x - w.x, v.y - w.y, v.z - w.z, v.w - w.w);
    }

    inline friend const vector4 operator*(const vector4 &v, const vector4 &w) {
        return vector4(v.x * w.x, v.y * w.y, v.z * w.z, v.w * w.w);
    }

    inline friend const vector4 operator/(const vector4 &v, const vector4 &w) {
        return vector4(v.x / w.x, v.y / w.y, v.z / w.z, v.w / w.w);
    }

    const vector4 operator-() const {
        return vector4(-x, -y, -z, -w);
    }

    inline friend vector4 operator+=(vector4 &v, const vector4 &w) {
        return v = v + w;
    }

    inline friend vector4 operator-=(vector4 &v, const vector4 &w) {
        return v = v - w;
    }

    inline friend vector4 operator*=(vector4 &v, const vector4 &w) {
        return v = v * w;
    }

    inline friend vector4 operator/=(vector4 &v, const vector4 &w) {
        return v = v / w;
    }

    const T& operator[](const uint index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        if (index == 3) return w;
        throw "Too big index for vector4";
    }

    T& operator[](const uint index) {
        return const_cast<T&>(
            static_cast<const vector4<T>& >(*this)[index]
        );
    }

    const vector3<T> xyz() const {
        return vector3<T>(x, y, z);
    }
};

template<typename T>
bool operator==(const vector4<T> &v, const vector4<T> &w) {
    return v.x == w.x
        && v.y == w.y
        && v.z == w.z
        && v.w == w.w;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const vector4<T>& v) {
    return out << "(" << v.x << "; " << v.y << "; " << v.z << "; " << v.w << ")";
}

template<typename T>
const T min(const vector4<T>& v) {
    return std::min(std::min(v.x, v.y), std::min(v.z, v.w));
}

template<typename T>
const T max(const vector4<T>& v) {
    return std::max(std::max(v.x, v.y), std::max(v.z, v.w));
}

template<typename T>
const vector4<T> min(const vector4<T>& v, const vector4<T>& w) {
    return vector4<T>(
        std::min(v.x, w.x),
        std::min(v.y, w.y),
        std::min(v.z, w.z),
        std::min(v.w, w.w)
    );
}

template<typename T>
const vector4<T> max(const vector4<T>& v, const vector4<T>& w) {
    return vector4<T>(
        std::max(v.x, w.x),
        std::max(v.y, w.y),
        std::max(v.z, w.z),
        std::max(v.w, w.w)
    );
}

///Dot production
template<typename T>
const T dot(const vector4<T>& v, const vector4<T>& w) {
    return v.x * w.x + v.y * w.y + v.z * w.z + v.w * w.w;
}

///Cross production
template<typename T>
const vector3<T> cross(const vector4<T> &v, const vector4<T> &w) {
    return vector3<T>(
        v.y * w.z - v.z * w.y,
        v.z * w.x - v.x * w.z,
        v.x * w.y - v.y * w.x
    );
}


using vec4 = vector4<float>;
using uvec4 = vector4<uint>;
using i16vec4 = vector4<short>;
using byte4 = vector4<unsigned char>;
using int4 = vector4<int>;

}

#endif // VECTOR4_H_INCLUDED
