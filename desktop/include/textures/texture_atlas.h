// PlaatCraft - Texture Atlas Header

#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H

#include <stdbool.h>
#include "glad/glad.h"

typedef struct TextureAtlas {
    char* path;
    int tile_size;
    bool is_transparent;
    GLuint texture_array;
} TextureAtlas;

TextureAtlas* texture_atlas_new(char* path, int tile_size, bool is_transparent);

void texture_atlas_enable(TextureAtlas* texture_atlas);

void texture_atlas_disable(TextureAtlas* texture_atlas);

void texture_atlas_free(TextureAtlas* texture_atlas);

#endif
