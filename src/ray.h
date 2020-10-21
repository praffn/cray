#ifndef RAY_H
#define RAY_H

#include "vec.h"

struct Ray
{
    Vec origin;
    Vec direction;
};

typedef struct Ray Ray;

Vec ray_at(Ray r, float t);

#endif