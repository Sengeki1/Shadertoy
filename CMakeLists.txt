cmake_minimum_required(VERSION 3.16)

# Specify the project name and languages
project(ShaderToy LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Libraries/include
    ${CMAKE_SOURCE_DIR}/Resources
    ${CMAKE_SOURCE_DIR}/Shaders
)

# Add glad as a library and specify its language
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/glad.c)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)

# Add executable
add_executable(ShaderToy 
    main.cpp
    glad.c
    stb.cpp
    Shaders/shaderClass.cpp
)

# Link glad, GLFW, and OpenGL
target_link_libraries(ShaderToy PRIVATE 
    glad
    opengl32.lib
    ${CMAKE_SOURCE_DIR}/Libraries/lib/glfw3.lib 
)
