// PlaatCraft - Plane Geometry Header

#ifndef PLANE_H
#define PLANE_H

#include "glad/glad.h"

#define PLANE_VERTICES_COUNT 6

extern float PLANE_VERTICES[];

typedef struct Plane {
    GLuint vertex_array;
    GLuint vertex_buffer;
} Plane;

Plane* plane_new(void);

void plane_enable(Plane* plane);

void plane_disable(Plane* plane);

void plane_free(Plane* plane);

#endif
