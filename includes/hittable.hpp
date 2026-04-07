#pragma once

#include "vec3.hpp"
#include "interval.hpp"
#include "ray.hpp"

namespace ssao_render{
    struct hit_point{
        vec3 p_;
        int pixel_i_;
        int pixel_j_;
        vec3 attenuation_color_{ 0.0f, 0.0f, 0.0f };
    };

    struct hittable{
        public:
            virtual ~hittable() = default;
            virtual bool hit(const ray &r, interval &ray_t, hit_point &hp) const = 0;
    };
}
