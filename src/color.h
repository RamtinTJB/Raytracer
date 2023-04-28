#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "vector.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel.color.y()) << ' '
        << static_cast<int>(255.999 * pixle_color.z()) << std::endl;
}

#endif
