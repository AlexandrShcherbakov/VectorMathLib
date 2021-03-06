#ifndef VECTOR3_H_INCLUDED
#define VECTOR3_H_INCLUDED

#include <iostream>

#include "main.h"

namespace VM {

template<typename T>
class vector3 {
public:
    const static uint Components = 3;

	///Coordinates
    T x, y, z;

    ///Constructors
    vector3(): x(T()), y(T()), z(T()) {}
    vector3(const T x, const T y, const T z): x(x), y(y), z(z) {}
    vector3(const T val): x(val), y(val), z(val) {}
    vector3(const T* coords): x(coords[0]), y(coords[1]), z(coords[2]) {}

    ///Operators
    inline friend const vector3 operator+(const vector3 &v, const vector3 &w) {
        return vector3(v.x + w.x, v.y + w.y, v.z + w.z);
    }

    inline friend const vector3 operator-(const vector3 &v, const vector3 &w) {
        return vector3(v.x - w.x, v.y - w.y, v.z - w.z);
    }

    inline friend const vector3 operator*(const vector3 &v, const vector3 &w) {
        return vector3(v.x * w.x, v.y * w.y, v.z * w.z);
    }

    inline friend const vector3 operator/(const vector3 &v, const vector3 &w) {
        return vector3(v.x / w.x, v.y / w.y, v.z / w.z);
    }

    const vector3 operator-() const {
        return vector3(-x, -y, -z);
    }

    inline friend vector3 operator+=(vector3 &v, const vector3 &w) {
        return v = v + w;
    }

    inline friend vector3 operator-=(vector3 &v, const vector3 &w) {
        return v = v - w;
    }

    inline friend vector3 operator*=(vector3 &v, const vector3 &w) {
        return v = v * w;
    }

    inline friend vector3 operator/=(vector3 &v, const vector3 &w) {
        return v = v / w;
    }

    const T& operator[](const uint index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        throw "Too big index for vector3";
    }

    T& operator[](const uint index) {
        return const_cast<T&>(
            static_cast<const vector3<T>& >(*this)[index]
        );
    }
};

template<typename T>
inline bool operator==(const vector3<T> &v, const vector3<T> &w) {
    return v.x == w.x
        && v.y == w.y
        && v.z == w.z;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const vector3<T>& v) {
    return out << "(" << v.x << "; " << v.y << "; " << v.z << ")";
}

template<typename T>
const T min(const vector3<T>& v) {
    return std::min(std::min(v.x, v.y), v.z);
}

template<typename T>
const T max(const vector3<T>& v) {
    return std::max(std::max(v.x, v.y), v.z);
}

template<typename T>
const vector3<T> min(const vector3<T>& v, const vector3<T>& w) {
    return vector3<T>(std::min(v.x, w.x), std::min(v.y, w.y), std::min(v.z, w.z));
}

template<typename T>
const vector3<T> max(const vector3<T>& v, const vector3<T>& w) {
    return vector3<T>(std::max(v.x, w.x), std::max(v.y, w.y), std::max(v.z, w.z));
}

///Dot production
template<typename T>
const T dot(const vector3<T>& v, const vector3<T>& w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

///Cross production
template<typename T>
const vector3<T> cross(const vector3<T> &v, const vector3<T> &w) {
    return vector3<T>(
        v.y * w.z - v.z * w.y,
        v.z * w.x - v.x * w.z,
        v.x * w.y - v.y * w.x
    );
}

template<typename T>
inline const vector3<T> apply(const vector3<T>& v, T (*func)(const T)) {
    return vector3<T>(func(v.x), func(v.y), func(v.z));
}

using vec3 = vector3<float>;
using uvec3 = vector3<uint>;
using ivec3 = vector3<int>;

}

#endif // VECTOR3_H_INCLUDED
