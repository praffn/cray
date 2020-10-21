#include "sphere.h"
#include "math.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

static bool hittable_sphere_hit(Hittable *h, Ray r, float t_min, float t_max, HitRecord *hr)
{
    Sphere *s = (void *)h;
    Vec oc = vec_sub(r.origin, s->center);
    float a = vec_mag2(r.direction);
    float half_b = vec_dot(oc, r.direction);
    float c = vec_mag2(oc) - s->radius * s->radius;
    float disc = half_b * half_b - a * c;

    if (disc > 0)
    {
        float root = sqrtf(disc);
        float tmp = (-half_b - root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            hr->t = tmp;
            hr->point = ray_at(r, tmp);
            hr->normal = vec_mul(
                vec_sub(hr->point, s->center),
                1.0 / s->radius);
            return true;
        }
        tmp = (-half_b + root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            hr->t = tmp;
            hr->point = ray_at(r, tmp);
            hr->normal = vec_mul(
                vec_sub(hr->point, s->center),
                1.0 / s->radius

            );
            return true;
        }
    }
    return false;
}

Hittable *hittable_sphere_make(Vec center, float radius)
{
    static const struct HittableInterface vtable = {
        hittable_sphere_hit};
    static Hittable base = {&vtable};
    Sphere *s = malloc(sizeof(*s));
    memcpy(&s->base, &base, sizeof(base));
    s->center = center;
    s->radius = radius;
    return &s->base;
}
