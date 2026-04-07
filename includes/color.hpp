#pragma once

#include "vec3.hpp"
#include "interval.hpp"

#include <iostream>

namespace ssao_render{
    void write_color(std::ostream &out, const vec3 &pixel_color)
    {
        float r = pixel_color.x();
        float g = pixel_color.y();
        float b = pixel_color.z();

        static const interval intensity{0.000f, 0.999f};
        int rbyte = int(255.999 * intensity.clamp(r));
        int gbyte = int(255.999 * intensity.clamp(g));
        int bbyte = int(255.999 * intensity.clamp(b));

        out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    }
}
