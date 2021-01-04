// PlaatCraft - Block Shader

#include "shaders/block_shader.h"
#include <stdlib.h>
#include "utils.h"
#include "log.h"

BlockShader* block_shader_new() {
    BlockShader* block_shader = malloc(sizeof(Shader));
    block_shader->shader = shader_new("assets/shaders/block.vert", "assets/shaders/block.frag");

    block_shader->block = block_new();

    // Get attributes
    block_shader->position_attribute = glGetAttribLocation(block_shader->shader->program, "a_position");
    glVertexAttribPointer(block_shader->position_attribute, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(block_shader->position_attribute);

    block_shader->texture_position_attribute = glGetAttribLocation(block_shader->shader->program, "a_texture_position");
    glVertexAttribPointer(block_shader->texture_position_attribute, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(block_shader->texture_position_attribute);

    block_shader->texture_face_attribute = glGetAttribLocation(block_shader->shader->program, "a_texture_face");
    glVertexAttribPointer(block_shader->texture_face_attribute, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(block_shader->texture_face_attribute);

    // Get uniforms
    block_shader->model_matrix_uniform = glGetUniformLocation(block_shader->shader->program, "u_model_matrix");
    block_shader->view_matrix_uniform = glGetUniformLocation(block_shader->shader->program, "u_view_matrix");
    block_shader->projection_matrix_uniform = glGetUniformLocation(block_shader->shader->program, "u_projection_matrix");
    block_shader->texture_indexes_uniform = glGetUniformLocation(block_shader->shader->program, "u_texture_indexes");

    return block_shader;
}

void block_shader_use(BlockShader* block_shader) {
    glUseProgram(block_shader->shader->program);
    block_use(block_shader->block);
}

void block_shader_free(BlockShader* block_shader) {
    block_free(block_shader->block);
    shader_free(block_shader->shader);
    free(block_shader);
}
