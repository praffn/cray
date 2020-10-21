#include "ray.h"

// Vec ray_point_at(Ray r, float t)
// {
//     return vec_add(r.origin, vec_mul(r.direction, t));
// }

Vec ray_at(Ray r, float t)
{
    return vec_add(r.origin, vec_mul(r.direction, t));
}