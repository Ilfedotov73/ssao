#pragma once 

#include "vec3.hpp"

namespace ssao_render{
    struct ray{
        private:
            vec3 orig_;
            vec3 dir_;
        public:
            ray(const vec3 &origin, const vec3 &direction) : orig_(origin), dir_(direction) {}

            const vec3 &ray_origin() const { return orig_; }
            const vec3 &ray_direction() const { return dir_; }

            vec3 ray_at(float t) const { return orig_ + t*dir_; }   
    };
}
