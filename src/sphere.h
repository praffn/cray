#ifndef SPHERE_H
#define SPHERE_H

#include "vec.h"
#include "hittable.h"

struct Sphere
{
    struct Hittable base;
    Vec center;
    float radius;
};

typedef struct Sphere Sphere;

Hittable *hittable_sphere_make(Vec center, float radius);

#endif