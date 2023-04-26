#ifndef RAYTRACER_VECTOR_H_
#define RAYTRACER_VECTOR_H_

#include <cmath>
#include <iostream>

class vec3 {
    public:
        vec3() : c{0, 0, 0} {}
        vec3(double c1, double c2, double c3) : c{c1, c2, c3} {}

        double x() const { return c[0]; }
        double y() const { return c[1]; }
        double z() const { return c[2]; }

        vec3 operator-() const { return vec3(-c[0], -c[1], -c[2]); }
        double operator[](int i) const { return c[i]; }
        double& operator[](int i) { return c[i]; }

        vec3& operator+=(const vec3& other) {
            c[0] += other[0];
            c[1] += other[1];
            c[2] += other[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            c[0] *= t;
            c[1] *= t;
            c[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length_squared() const {
            return c[0]*c[0] + c[1]*c[1] + c[2]*c[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }

    private:
        double c[3];
};

using point3 = vec3;
using color  = vec3;

inline bool operator==(const vec3& lhs, const vec3& rhs) {
    return (lhs[0] == rhs[0]) && (lhs[1] == rhs[1]) && (lhs[2] == rhs[2]);
}

inline bool operator!=(const vec3& lhs, const vec3& rhs) {
    return !(lhs == rhs);
}

inline vec3 operator+(vec3 lhs, const vec3& rhs) {
    return lhs += rhs;
}

inline vec3 operator-(vec3 lhs, const vec3& rhs) {
    return lhs += -rhs;
}

inline vec3 operator*(const vec3& lhs, const vec3& rhs) {
    return vec3(lhs[0]*rhs[0], lhs[1]*rhs[1], lhs[2]*rhs[2]);
}

inline vec3 operator*(const double t, vec3 rhs) {
    return rhs *= t;
}

inline vec3 operator*(vec3 lhs, const double t) {
    return t * lhs;
}

inline vec3 operator/(vec3 lhs, const double t) {
    return (1/t) * lhs;
}

inline std::ostream& operator<<(std::ostream& os, const vec3& rhs) {
    return os << "<" << rhs[0] << ", " << rhs[1] << ", " << rhs[2] << ">";
}

inline double dot(const vec3& u, const vec3& v) {
    return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3( u.y()*v.z() - u.z()*v.y(),
                 u.z()*v.x() - u.x()*v.z(),
                 u.x()*v.y() - u.y()*v.x());
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif
