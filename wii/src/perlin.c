// Adapted from: https://mrl.cs.nyu.edu/~perlin/noise/

#include "perlin.h"

#include <math.h>

int64_t perlin_seed;

int32_t perlin_p[512];

int32_t perlin_permutation[256] = {
    151, 160, 137, 91,  90,  15,  131, 13,  201, 95,  96,  53,  194, 233, 7,   225, 140, 36,  103, 30,  69,  142,
    8,   99,  37,  240, 21,  10,  23,  190, 6,   148, 247, 120, 234, 75,  0,   26,  197, 62,  94,  252, 219, 203,
    117, 35,  11,  32,  57,  177, 33,  88,  237, 149, 56,  87,  174, 20,  125, 136, 171, 168, 68,  175, 74,  165,
    71,  134, 139, 48,  27,  166, 77,  146, 158, 231, 83,  111, 229, 122, 60,  211, 133, 230, 220, 105, 92,  41,
    55,  46,  245, 40,  244, 102, 143, 54,  65,  25,  63,  161, 1,   216, 80,  73,  209, 76,  132, 187, 208, 89,
    18,  169, 200, 196, 135, 130, 116, 188, 159, 86,  164, 100, 109, 198, 173, 186, 3,   64,  52,  217, 226, 250,
    124, 123, 5,   202, 38,  147, 118, 126, 255, 82,  85,  212, 207, 206, 59,  227, 47,  16,  58,  17,  182, 189,
    28,  42,  223, 183, 170, 213, 119, 248, 152, 2,   44,  154, 163, 70,  221, 153, 101, 155, 167, 43,  172, 9,
    129, 22,  39,  253, 19,  98,  108, 110, 79,  113, 224, 232, 178, 185, 112, 104, 218, 246, 97,  228, 251, 34,
    242, 193, 238, 210, 144, 12,  191, 179, 162, 241, 81,  51,  145, 235, 249, 14,  239, 107, 49,  192, 214, 31,
    181, 199, 106, 157, 184, 84,  204, 176, 115, 121, 50,  45,  127, 4,   150, 254, 138, 236, 205, 93,  222, 114,
    67,  29,  24,  72,  243, 141, 128, 195, 78,  66,  215, 61,  156, 180};

void perlin_init(int64_t seed) {
    perlin_seed = seed;
    for (int32_t i = 0; i < 256; i++) {
        perlin_p[256 + i] = perlin_p[i] = perlin_permutation[i];
    }
}

double perlin_fade(double t) { return t * t * t * (t * (t * 6 - 15) + 10); }

double perlin_lerp(double t, double a, double b) { return a + t * (b - a); }

double perlin_grad(int32_t hash, double x, double y, double z) {
    int32_t h = hash & 15;     // CONVERT LO 4 BITS OF HASH CODE
    double u = h < 8 ? x : y,  // INTO 12 GRADIENT DIRECTIONS.
        v = h < 4                ? y
            : h == 12 || h == 14 ? x
                                 : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

double perlin_noise(double x, double y, double z) {
    // Add seed to position
    x += perlin_seed;
    y += perlin_seed;
    z -= perlin_seed;

    // Do perlin stuff
    int32_t X = (int32_t)floor(x) & 255,  // FIND UNIT CUBE THAT
        Y = (int32_t)floor(y) & 255,      // CONTAINS POINT.
        Z = (int32_t)floor(z) & 255;

    x -= floor(x);  // FIND RELATIVE X,Y,Z
    y -= floor(y);  // OF POINT IN CUBE.
    z -= floor(z);

    double u = perlin_fade(x),  // COMPUTE FADE CURVES
        v = perlin_fade(y),     // FOR EACH OF X,Y,Z.
        w = perlin_fade(z);

    int32_t A = perlin_p[X] + Y, AA = perlin_p[A] + Z, AB = perlin_p[A + 1] + Z,  // HASH COORDINATES OF
        B = perlin_p[X + 1] + Y, BA = perlin_p[B] + Z, BB = perlin_p[B + 1] + Z;  // THE 8 CUBE CORNERS,

    return perlin_lerp(w,
                       perlin_lerp(v,
                                   perlin_lerp(u, perlin_grad(perlin_p[AA], x, y, z),         // AND ADD
                                               perlin_grad(perlin_p[BA], x - 1, y, z)),       // BLENDED
                                   perlin_lerp(u, perlin_grad(perlin_p[AB], x, y - 1, z),     // RESULTS
                                               perlin_grad(perlin_p[BB], x - 1, y - 1, z))),  // FROM  8
                       perlin_lerp(v,
                                   perlin_lerp(u, perlin_grad(perlin_p[AA + 1], x, y, z - 1),    // CORNERS
                                               perlin_grad(perlin_p[BA + 1], x - 1, y, z - 1)),  // OF CUBE
                                   perlin_lerp(u, perlin_grad(perlin_p[AB + 1], x, y - 1, z - 1),
                                               perlin_grad(perlin_p[BB + 1], x - 1, y - 1, z - 1))));
}
