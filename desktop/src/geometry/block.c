// PlaatCraft - Block Geometry

#include "geometry/block.h"
#include <stdlib.h>

char* BLOCK_TYPE_NAMES[BLOCK_TYPE_SIZE] = {
    "Air",

    "Grass",
    "Dirt",
    "Water",

    "Sand Top",
    "Sand",
    "Stone",
    "Coal",
    "Gold",

    "Oak Trunk",
    "Beech Trunk",

    "Green Leaves",
    "Orange Leaves",
    "Cactus",

    "Brown Wood",
    "Red Wood",

    "Gray Bricks",
    "Red Bricks",

    "Selected"
};

BlockTexture BLOCK_TYPE_TEXTURE_FACES[BLOCK_TYPE_SIZE][6] = {
    { 0, 0, 0, 0, 0, 0 }, // Air

    { BLOCK_TEXTURE_GRASS_TOP, BLOCK_TEXTURE_GRASS_SIDE, BLOCK_TEXTURE_GRASS_SIDE, BLOCK_TEXTURE_GRASS_SIDE, BLOCK_TEXTURE_GRASS_SIDE, BLOCK_TEXTURE_DIRT }, // Grass
    { BLOCK_TEXTURE_DIRT, BLOCK_TEXTURE_DIRT, BLOCK_TEXTURE_DIRT, BLOCK_TEXTURE_DIRT, BLOCK_TEXTURE_DIRT, BLOCK_TEXTURE_DIRT }, // Dirt
    { BLOCK_TEXTURE_WATER, BLOCK_TEXTURE_WATER, BLOCK_TEXTURE_WATER, BLOCK_TEXTURE_WATER, BLOCK_TEXTURE_WATER, BLOCK_TEXTURE_WATER }, // Water

    { BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND }, // Sand Top
    { BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND, BLOCK_TEXTURE_SAND }, // Sand
    { BLOCK_TEXTURE_STONE, BLOCK_TEXTURE_STONE, BLOCK_TEXTURE_STONE, BLOCK_TEXTURE_STONE, BLOCK_TEXTURE_STONE, BLOCK_TEXTURE_STONE }, // Stone
    { BLOCK_TEXTURE_COAL, BLOCK_TEXTURE_COAL, BLOCK_TEXTURE_COAL, BLOCK_TEXTURE_COAL, BLOCK_TEXTURE_COAL, BLOCK_TEXTURE_COAL }, // Coal
    { BLOCK_TEXTURE_GOLD, BLOCK_TEXTURE_GOLD, BLOCK_TEXTURE_GOLD, BLOCK_TEXTURE_GOLD, BLOCK_TEXTURE_GOLD, BLOCK_TEXTURE_GOLD }, // Goal

    { BLOCK_TEXTURE_OAK_TRUNK_TOP, BLOCK_TEXTURE_OAK_TRUNK_SIDE, BLOCK_TEXTURE_OAK_TRUNK_SIDE, BLOCK_TEXTURE_OAK_TRUNK_SIDE, BLOCK_TEXTURE_OAK_TRUNK_SIDE, BLOCK_TEXTURE_OAK_TRUNK_TOP }, // Oak Trunk
    { BLOCK_TEXTURE_BEECH_TRUNK_TOP, BLOCK_TEXTURE_BEECH_TRUNK_SIDE, BLOCK_TEXTURE_BEECH_TRUNK_SIDE, BLOCK_TEXTURE_BEECH_TRUNK_SIDE, BLOCK_TEXTURE_BEECH_TRUNK_SIDE, BLOCK_TEXTURE_BEECH_TRUNK_TOP }, // Beech Trunk

    { BLOCK_TEXTURE_GREEN_LEAVES, BLOCK_TEXTURE_GREEN_LEAVES, BLOCK_TEXTURE_GREEN_LEAVES, BLOCK_TEXTURE_GREEN_LEAVES, BLOCK_TEXTURE_GREEN_LEAVES, BLOCK_TEXTURE_GREEN_LEAVES }, // Green Leaves
    { BLOCK_TEXTURE_ORANGE_LEAVES, BLOCK_TEXTURE_ORANGE_LEAVES, BLOCK_TEXTURE_ORANGE_LEAVES, BLOCK_TEXTURE_ORANGE_LEAVES, BLOCK_TEXTURE_ORANGE_LEAVES, BLOCK_TEXTURE_ORANGE_LEAVES }, // Orange Leaves
    { BLOCK_TEXTURE_CACTUS_TOP, BLOCK_TEXTURE_CACTUS_SIDE, BLOCK_TEXTURE_CACTUS_SIDE, BLOCK_TEXTURE_CACTUS_SIDE, BLOCK_TEXTURE_CACTUS_SIDE, BLOCK_TEXTURE_CACTUS_TOP }, // Cactus

    { BLOCK_TEXTURE_BROWN_WOOD, BLOCK_TEXTURE_BROWN_WOOD, BLOCK_TEXTURE_BROWN_WOOD, BLOCK_TEXTURE_BROWN_WOOD, BLOCK_TEXTURE_BROWN_WOOD, BLOCK_TEXTURE_BROWN_WOOD }, // Brown Wood
    { BLOCK_TEXTURE_RED_WOOD, BLOCK_TEXTURE_RED_WOOD, BLOCK_TEXTURE_RED_WOOD, BLOCK_TEXTURE_RED_WOOD, BLOCK_TEXTURE_RED_WOOD, BLOCK_TEXTURE_RED_WOOD }, // Red Wood
    { BLOCK_TEXTURE_GRAY_BRICKS, BLOCK_TEXTURE_GRAY_BRICKS, BLOCK_TEXTURE_GRAY_BRICKS, BLOCK_TEXTURE_GRAY_BRICKS, BLOCK_TEXTURE_GRAY_BRICKS, BLOCK_TEXTURE_GRAY_BRICKS}, // Gray Bricks
    { BLOCK_TEXTURE_RED_BRICKS, BLOCK_TEXTURE_RED_BRICKS, BLOCK_TEXTURE_RED_BRICKS, BLOCK_TEXTURE_RED_BRICKS, BLOCK_TEXTURE_RED_BRICKS, BLOCK_TEXTURE_RED_BRICKS }, // Red Bricks

    { BLOCK_TEXTURE_SELECTED, BLOCK_TEXTURE_SELECTED, BLOCK_TEXTURE_SELECTED, BLOCK_TEXTURE_SELECTED, BLOCK_TEXTURE_SELECTED, BLOCK_TEXTURE_SELECTED } // Selected
};

char* BLOCK_SIDE_NAMES[BLOCK_SIDE_SIZE] = {
    "left",
    "right",
    "above",
    "below",
    "front",
    "back"
};

float BLOCK_VERTICES[] = {
    // Vertex position, Texture position, Texture face
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  1.f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,  1.f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  1.f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  1.f,
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,  1.f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  1.f,

    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  6.f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  6.f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  6.f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  6.f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  6.f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,  6.f,

    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  2.f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  2.f,
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  2.f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  2.f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  2.f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  2.f,

     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  4.f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  4.f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  4.f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  4.f,
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  4.f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  4.f,

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  5.f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  5.f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  5.f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  5.f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  5.f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  5.f,

    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,  3.f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  3.f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  3.f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  3.f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  3.f,
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,  3.f
};

Block* block_new(void) {
    Block* block = malloc(sizeof(Block));

    glGenVertexArrays(1, &block->vertex_array);
    block_enable(block);

    glGenBuffers(1, &block->vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, block->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(BLOCK_VERTICES), BLOCK_VERTICES, GL_STATIC_DRAW);

    block_disable(block);

    return block;
}

void block_enable(Block* block) {
    glBindVertexArray(block->vertex_array);
}

void block_disable(Block* block) {
    (void)block;
    glBindVertexArray(0);
}

void block_free(Block* block) {
    glDeleteVertexArrays(1, &block->vertex_array);
    glDeleteBuffers(1, &block->vertex_buffer);
    free(block);
}
