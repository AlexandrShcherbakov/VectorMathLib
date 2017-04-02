#ifndef BYTE4_H_INCLUDED
#define BYTE4_H_INCLUDED

namespace VM {

std::ostream& operator<<(std::ostream& out, const byte4& v) {
    return out << "(" <<
        static_cast<int>(v.x) << "; " <<
        static_cast<int>(v.y) << "; " <<
        static_cast<int>(v.z) << "; " <<
        static_cast<int>(v.w) << ")";
}

}

#endif // BYTE4_H_INCLUDED
