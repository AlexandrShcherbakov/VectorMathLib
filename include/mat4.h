#ifndef MAT4_H
#define MAT4_H

#include <array>

#include "vec4.h"

namespace VM {

class mat4 {
public:
    constexpr static uint Side = 4;
    constexpr static uint ValuesCount = sqr(Side);

    ///Constructors
    mat4();
    mat4(const float diagNum);
    mat4(const float* elements);
    mat4(const float** elements);

    ///Operators
    vec4 operator*(const vec4 &v) const;
    mat4 operator*(const mat4 &m) const;
    mat4 operator+(const mat4 &m) const;
    mat4 operator+=(const mat4 &m);
    mat4 operator*=(const mat4 &m);
    vec4& operator[](const uint index);
    const vec4& operator[](const uint index) const;

    friend std::ostream& operator<<(std::ostream& os, const mat4& v);

    ///Other methods
    vec4 col(const int index) const;
    mat4 unmatrixN3() const;
    std::array<float, sqr(Side)> data() const;

protected:
    ///Rows
    std::array<vec4, Side> rows;
};

///Transpose matrix
mat4 transpose(const mat4& m);

}

#endif // MAT4_H
