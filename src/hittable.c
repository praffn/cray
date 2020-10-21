#include "hittable.h"

bool hittable_hit(Hittable *h, Ray r, float t_min, float t_max, HitRecord *hr)
{
    return h->vtable->hit(h, r, t_min, t_max, hr);
}