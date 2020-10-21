#include "vec.h"
#include "stdio.h"
#include "math.h"

Vec vec_make(float x, float y, float z)
{
    return (Vec){
        x, y, z};
}

Vec vec_add(Vec a, Vec b)
{
    Vec v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    return v;
}

Vec vec_sub(Vec a, Vec b)
{
    Vec v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}

Vec vec_mul(Vec a, float f)
{
    Vec v;
    v.x = a.x * f;
    v.y = a.y * f;
    v.z = a.z * f;
    return v;
}

void vec_print(Vec a)
{
    printf("[%.2f, %.2f, %.2f]", a.x, a.y, a.z);
}

Vec vec_norm(Vec a)
{
    return vec_mul(a, 1.0 / vec_mag(a));
}

float vec_mag(Vec a)
{
    return sqrtf(vec_mag2(a));
}

float vec_mag2(Vec a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float vec_dot(Vec a, Vec b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec vec_cross(Vec a, Vec b)
{
    Vec v;
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return v;
}