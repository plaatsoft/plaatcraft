// PlaatCraft - Game Header

#ifndef GAME_H
#define GAME_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "font.h"
#include "shaders/block_shader.h"
#include "shaders/flat_shader.h"
#include "textures/texture_atlas.h"
#include "textures/texture.h"
#include "camera.h"
#include "math/vector4.h"
#include "world.h"

typedef struct Game {
    char* title;
    int width;
    int height;
    float scale_x;
    float scale_y;
    int oldWidth;
    int oldHeight;

    GLFWwindow* window;
    bool is_playing;
    bool is_fullscreen;
    bool is_debugged;
    int fps;

    Font* text_font;

    BlockShader* block_shader;
    FlatShader* flat_shader;

    TextureAtlas* blocks_texture_atlas;
    TextureAtlas* selected_texture_atlas;
    Texture* cursor_texture;

    Camera* camera;
    World* world;

    BlockPosition* selected_block;
    BlockType selected_block_type;
    Vector4 selected_block_rotation;
} Game;

void game_init(void);

void game_size_callback(GLFWwindow* window, int width, int height);

void game_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void game_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

void game_cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void game_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void game_content_scale_callback(GLFWwindow* window, float scale_x, float scale_y);

Game* game_new(char* title, int width, int height);

void game_update(Game* game, float delta);

void game_render(Game* game, float delta);

void game_start(Game* game);

void game_free(Game* game);

#endif
