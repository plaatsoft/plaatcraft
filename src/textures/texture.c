// PlaatCraft - Texture

#include "textures/texture.h"
#include <stdlib.h>
#include "stb_image/stb_image.h"
#include "log.h"

Texture* texture_new(char* path, bool is_transparent) {
    Texture* texture = malloc(sizeof(texture));
    texture->path = path;
    texture->is_transparent = is_transparent;

    int32_t image_channels;
    uint8_t* image_buffer = stbi_load(path, &texture->width, &texture->height, &image_channels, is_transparent ? STBI_rgb_alpha : STBI_rgb);
    if (!image_buffer) {
        log_error("Can't load image %s", path);
    }

    glGenTextures(1, &texture->texture);
    texture_enable(texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, is_transparent ? GL_RGBA : GL_RGB, texture->width, texture->height, 0, is_transparent ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image_buffer);

    stbi_image_free(image_buffer);

    glGenerateMipmap(GL_TEXTURE_2D);

    texture_disable(texture);

    return texture;
}

void texture_enable(Texture* texture) {
    if (texture->is_transparent) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    glBindTexture(GL_TEXTURE_2D, texture->texture);
}

void texture_disable(Texture* texture) {
    glBindTexture(GL_TEXTURE_2D, 0);

    if (texture->is_transparent) {
        glDisable(GL_BLEND);
    }
}

void texture_free(Texture* texture) {
    glDeleteTextures(1, &texture->texture);
    free(texture);
}
