# PlaatCraft - CMake build file
cmake_minimum_required(VERSION 3.10)

# Project version
project(plaatcraft VERSION 0.7)

# Use the C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

# Set debug flag when using debug configuration
set(CMAKE_C_FLAGS_DEBUG "-DDEBUG")

### LIBRARIES ###

# GLFW3 headers
find_package(PkgConfig)
pkg_check_modules(GLFW3 REQUIRED glfw3)

# Glad Library
add_library(glad src/glad/glad.c)
target_include_directories(glad PRIVATE include)

# STB Image Library
add_library(stb_image src/stb_image/stb_image.c)
target_include_directories(stb_image PRIVATE include)

# STB TrueType Library
add_library(stb_truetype src/stb_truetype/stb_truetype.c)
target_include_directories(stb_truetype PRIVATE include)

# Tiny C Thread Library
add_library(tinycthread src/tinycthread/tinycthread.c)
target_include_directories(tinycthread PRIVATE include)

# Perlin Noise Library
add_library(perlin src/perlin/perlin.c)
target_include_directories(perlin PRIVATE include)

### MAIN EXECUTABLE ###

# Config file generator
configure_file(include/config.h.in ../include/config.h)

# Create main executable
add_executable(
    ${PROJECT_NAME} src/main.c src/log.c src/utils.c src/random.c src/font.c
    src/geometry/block.c src/geometry/plane.c
    src/math/vector4.c src/math/matrix4.c
    src/shaders/shader.c src/shaders/block_shader.c src/shaders/flat_shader.c
    src/textures/texture.c src/textures/texture_atlas.c src/textures/text_texture.c
    src/game.c src/camera.c src/chunk.c src/database.c src/world.c
)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW3_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

# Link main executable with external libs
if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-static -Wl,--subsystem,windows")
    target_link_libraries(${PROJECT_NAME} PRIVATE glad stb_image stb_truetype tinycthread perlin
        glfw3 sqlite3
    )
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE glad stb_image stb_truetype tinycthread perlin
        ${GLFW3_LINK_LIBRARIES} sqlite3 m dl pthread
    )
endif()

### ASSETS ###

# Copy assets folder to build folder
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
