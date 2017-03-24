#ifndef VEC3_H
#define VEC3_H

#include <algorithm>
#include <iostream>

#include "main.h"
#include "vector3.h"


namespace VM {

bool operator==(const vec3 &v, const vec3& w);

///Length of vector for similarity to openGL syntax
float length(const vec3 &v);

vec3 normalize(const vec3 &v);

///Cosine between two vectors
float cos(const vec3 &v, const vec3 &w);

inline const vec3 log(const vec3& v) {
    return apply(v, std::log);
}

}
#endif // VEC3_H
