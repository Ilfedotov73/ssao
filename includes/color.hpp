#pragma once

#include "vec3.hpp"

#include <iostream>

namespace ssao_render{
    void write_color(std::ostream &out, const vec3 &pixel_color)
    {
        vec3 r = pixel_color.x();
        vec3 g = pixel_color.y();
        vec3 b = pixel_color.z();

        int rbyte = int(255.999 * r);
        int gbyte = int(255.999 * g);
        int bbyte = int(255.999 * b);

        out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    }
}
