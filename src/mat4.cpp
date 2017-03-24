#include "mat4.h"

namespace VM {

///Constructors
mat4::mat4() {};

mat4::mat4(const float diagNum) {
	for (uint i = 0; i < Side; ++i) {
		for (uint j = 0; j < Side; ++j) {
			rows[i][j] = 0.0f;
		}
	}
    for (uint i = 0; i < Side; ++i) {
        rows[i][i] = diagNum;
    }
}

mat4::mat4(const float* elements) {
    for (uint i = 0; i < Side; ++i) {
        for (uint j = 0; j < Side; ++j) {
            rows[i][j] = elements[i * 4 + j];
        }
    }
}

mat4::mat4(const float** elements) {
    for (uint i = 0; i < Side; ++i) {
        for (uint j = 0; j < Side; ++j) {
            rows[i][j] = elements[i][j];
        }
    }
}

///Operators
vec4 mat4::operator*(const vec4 &v) const {
    vec4 res;
    for (uint i = 0; i < Side; ++i) {
        res[i] = dot(rows[i], v);
    }
    return res;
}

mat4 mat4::operator*(const mat4 &m) const {
    mat4 res;
    for (uint i = 0; i < Side; ++i) {
        for (uint j = 0; j < Side; ++j) {
            res[i][j] = dot(rows[i], m.col(j));
        }
    }
    return res;
}

mat4 mat4::operator+(const mat4 &m) const{
    mat4 res;
    for (uint i = 0; i < Side; ++i) {
        for (uint j = 0; j < Side; ++j) {
            res[i][j] = rows[i][j] + m[i][j];
        }
    }
    return res;
}

mat4 mat4::operator+=(const mat4 &m) {
    return (*this) = (*this) + m;
}

mat4 mat4::operator*=(const mat4 &m) {
	return (*this) = (*this) * m;
}

vec4& mat4::operator[](const uint index) {
    if (index >= Side) throw "Too big row index for matrix";
    return rows[index];
}

const vec4& mat4::operator[](const uint index) const{
    if (index >= Side) throw "Too big row index for matrix";
    return rows[index];
}

std::ostream& operator<<(std::ostream& os, const mat4& v) {
    os.precision(8);
    os << std::fixed;
    for (uint i = 0; i < v.Side; ++i) {
        for (uint j = 0; j < v.Side; ++j) {
            os << "\t" << v[i][j];
        }
        os << "\n";
    }
    return os;
}


///Other methods

///Get column
vec4 mat4::col(const int index) const {
    vec4 res;
    for (uint i = 0; i < Side; ++i) {
        res[i] = rows[i][index];
    }
    return res;
}

mat4 mat4::unmatrixN3() const {
    mat4 m = *this;
    mat4 um(1.0f);
    for (uint i = 0; i < Side; ++i) {
        ///Choose row with non-null i-coord
        uint j;
        for (j = i; j < Side && m[j][i] == 0; ++j);
        std::swap(m[i], m[j]);
        std::swap(um[i], um[j]);

        ///Substract row from last rows
        for (uint j = i + 1; j < Side; ++j) {
            um[j] -= um[i] / m[i][i] * m[j][i];
            m[j] -= m[i] / m[i][i] * m[j][i];

        }
    }
    float determinant = 1.0;
    for (uint i = 0; i < Side; ++i) {
        determinant *= m[i][i];
    }
    for (int i = Side - 1; i >= 0; --i) {
        um[i] /= m[i][i];
        m[i] /= m[i][i];
        for (int j = i - 1; j >= 0; --j) {
            um[j] -= um[i] * m[j][i];
            m[j] -= m[i] * m[j][i];
        }
    }
    return um;
}

std::array<float, mat4::ValuesCount> mat4::data() const {
	std::array<float, ValuesCount> res;
    for (uint i = 0; i < ValuesCount; ++i) {
		res[i] = (*this)[i / Side][i % Side];
    }
	return res;
}

///Transpose matrix
mat4 transpose(const mat4& m) {
    mat4 res;
    for (uint i = 0; i < m.Side; ++i) {
        for (uint j = 0; j < m.Side; ++j) {
            res[i][j] = m[j][i];
        }
    }
    return res;
}

}
