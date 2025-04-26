#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <iostream>
#include <cmath>
#include <limits>
#include <memory>

//std strings
using std::make_shared;
using std::shared_ptr;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//util funcs
inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

//common headers
#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif