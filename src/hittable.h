#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "stdbool.h"

struct HitRecord
{
    Vec point;
    Vec normal;
    float t;
};

typedef struct HitRecord HitRecord;

struct Hittable
{
    const struct HittableInterface *vtable;
};

typedef struct Hittable Hittable;

struct HittableInterface
{
    bool (*hit)(Hittable *h, Ray r, float t_min, float t_max, HitRecord *hr);
};

bool hittable_hit(Hittable *h, Ray r, float t_min, float t_max, HitRecord *hr);

#endif