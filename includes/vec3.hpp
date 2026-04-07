#pragma once

#include <iostream>
#include <cmath>

namespace ssao_render{
    struct vec3{
        private:
            float e_[3];
        public:
            vec3() : e_{ 0.0f, 0.0f, 0.0f } {}
            vec3(float e0, float e1, float e2) : e_{ e0, e1, e2 } {}
            
            float x() const { return e_[0]; }
            float y() const { return e_[1]; }
            float z() const { return e_[2]; }

            vec3 operator-() const { return vec3(-e_[0], -e_[1], -e_[2]); }
            float operator[](int i) const { return e_[i]; }
            float &operator[](int i) { return e_[i]; }

            vec3 &operator+=(const vec3 &v) 
            {
                e_[0] += v.e_[0];
                e_[1] += v.e_[1];
                e_[2] += v.e_[2];
                return *this;
            }

            vec3 &operator*=(float t) 
            {
                e_[0] *= t;
                e_[1] *= t;
                e_[2] *= t;
                return *this;
            }

            vec3 &operator/=(float t) { return *this *= 1/t; }
            
            float vec3_length_squared() const { return e_[0]*e_[0] + e_[1]*e_[1] + e_[2]*e_[2]; }           
            float vec3_length() const { return std::sqrt(vec3_length_squared()); }
           
    };

    inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
    {
        return out << v.x() << ' ' << v.y() << ' ' << v.z();
    }

    inline vec3 operator+(const vec3 &u, const vec3 &v)
    {
        return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
    }

    inline vec3 operator-(const vec3 &u, const vec3 &v)
    {
        return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
    }

    inline vec3 operator*(const vec3 &u, const vec3 &v)
    {
        return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
    }
    inline vec3 operator*(float t, const vec3 &v) 
    {
        return vec3(t*v.x(), t*v.y(), t*v.z());
    }
    inline vec3 operator*(const vec3 &u, float t) { return t * u; }

    inline vec3 operator/(const vec3 &u, float t) { return (1/t) * u; }

    inline float vec3_dot(const vec3 &u, const vec3 &v) 
    {
        return u.x() * v.x() 
             + u.y() * v.y() 
             + u.z() * v.z();    
    }

    inline vec3 vec3_cross(const vec3 &u, const vec3 &v) 
    {
        return vec3(u.y() * v.z() - u.z() * v.y(),
                    u.z() * v.x() - u.x() * v.z(),
                    u.x() * v.y() - u.y() * v.z());
    }

    inline vec3 vec3_unit_vector(const vec3& u) { return u / u.vec3_length(); }
}
