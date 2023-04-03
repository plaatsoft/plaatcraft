// PlaatCraft - Shader Header

#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"

typedef struct Shader {
    char* vertex_path;
    char* fragment_path;
    GLuint program;
} Shader;

Shader* shader_new(char* vertex_path, char* fragment_path);

void shader_enable(Shader* shader);

void shader_free(Shader* shader);

#endif
