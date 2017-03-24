#ifndef VEC4_H
#define VEC4_H

#include <algorithm>

#include "vector4.h"

namespace VM {

bool operator==(const vec4 &v, const vec4& w);

bool operator!=(const vec4& v, const vec4& w);

float length(const vec4 &v);

vec4 normalize(const vec4& v);

}
#endif // VEC4_H
