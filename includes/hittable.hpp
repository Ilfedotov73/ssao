#pragma once

namespace ssao_render{
    struct hit_point{
        vec3 p_;
        int pixel_i_;
        int pixel_j_;
        vec3 color_{ 0.0f, 0.0f, 0.0f };
    };

    struct hittable{
        public:
            virtual ~hittable() = default;
            virtual bool hit(const ray &r, float ray_tmin, float ray_tmax, hit_point &hp) const = 0;
    };
}
