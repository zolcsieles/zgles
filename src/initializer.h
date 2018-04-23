#pragma once

#define EGL_DYNAMIC_LOAD
#define GL_GLES_PROTOTYPES 0
#include <EGL/egl.h>
#include <GLES2/gl2.h>

class Initializer
{
public:
    Initializer();
    ~Initializer();
};

