#ifndef SHADER_HPP
#define SHADER_HPP
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include "stb_image.cpp"


GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

#endif