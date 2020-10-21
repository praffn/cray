#ifndef VEC_H
#define VEC_H

struct Vec
{
    float x;
    float y;
    float z;
};

typedef struct Vec Vec;

Vec vec_make(float x, float y, float z);
Vec vec_add(Vec a, Vec b);
Vec vec_sub(Vec a, Vec b);
Vec vec_mul(Vec a, float f);
Vec vec_norm(Vec a);
float vec_mag(Vec a);
float vec_mag2(Vec a);
float vec_dot(Vec a, Vec b);
Vec vec_cross(Vec a, Vec b);

void vec_print(Vec a);

#endif