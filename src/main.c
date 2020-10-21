#include "stdlib.h"
#include "lodepng.h"
#include "vec.h"
#include "stdbool.h"
#include "ray.h"
#include "math.h"
#include "sphere.h"

Hittable *hittable;

Vec ray_color(Ray r)
{
    HitRecord h;

    if (hittable_hit(hittable, r, 0, 100000, &h))
    {
        Vec normal = vec_norm(
            vec_sub(
                ray_at(r, h.t),
                vec_make(0, 0, -1)));
        return vec_make((normal.x + 1) * 0.5,
                        (normal.y + 1) * 0.5,
                        (normal.z + 1) * 0.5);
    }
    Vec unit_dir = vec_norm(r.direction);
    h.t = 0.5 * (unit_dir.y + 1);
    Vec color_a = vec_make(1, 1, 1);
    Vec color_b = vec_make(0.5, 0.7, 1);
    return vec_add(
        vec_mul(color_a, 1 - h.t),
        vec_mul(color_b, h.t));
}

int main(int argc, char **argv)
{
    hittable = hittable_sphere_make(
        vec_make(0, 0, -1),
        0.5);

    // image
    const char *filename = "test.png";
    int aspect_ratio = 16.0 / 9.0;
    unsigned int width = 256;
    unsigned int height = width / aspect_ratio;
    unsigned char *image = malloc(width * height * 4);

    // camera
    float vh = 2.0;
    float vw = aspect_ratio * vh;
    float focal_length = 1.0;
    Vec origin = vec_make(0, 0, 0);
    Vec horizontal = vec_make(vw, 0, 0);
    Vec vertical = vec_make(0, vh, 0);

    Vec llc = vec_sub(
        vec_sub(
            vec_sub(
                origin,
                vec_mul(horizontal, 1.0 / 2.0)),
            vec_mul(vertical, 1.0 / 2.0)),
        vec_make(0, 0, focal_length));

    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            float u = ((float)x) / (width - 1);
            float v = ((float)y) / (height - 1);
            Ray r;
            r.origin = origin;
            r.direction = vec_sub(
                vec_add(
                    vec_add(
                        llc,
                        vec_mul(horizontal, u)),
                    vec_mul(vertical, v)),
                origin);
            Vec pixel = ray_color(r);

            int yy = height - y;

            image[4 * width * yy + 4 * x + 0] = (char)(255 * pixel.x);
            image[4 * width * yy + 4 * x + 1] = (char)(255 * pixel.y);
            image[4 * width * yy + 4 * x + 2] = (char)(255 * pixel.z);
            image[4 * width * yy + 4 * x + 3] = 255;
        }
    }

    lodepng_encode32_file(filename, image, width, height);

    free(image);
    return 0;
}