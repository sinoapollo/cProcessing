//
//  OpenGLAgent.h
//  Processing
//
//  Created by 中国美术学院 陈天翼(Apollo Chen) on 1/28/19.
//  Copyright © 2019 Apollo Chen. All rights reserved.
//

#ifndef OPENGLAGENT_H
#define OPENGLAGENT_H

//#ifdef  __unix// or #ifdef  __unix__
//#ifdef  __linux// or #ifdef  __linux__
//#ifdef  __FreeBSD__
//#ifdef  _WIN32£¨»òÕßWIN32£©
//#ifdef  _WIN64
//#ifdef __APPLE__
// #if TARGET_IPHONE_SIMULATOR
// #elif TARGET_OS_IPHONE
// #elif TARGET_OS_MAC
// #else
//# error "Unknown Apple platform"...
// #endif
#ifdef __linux__
#include <gl/glcorearb.h>
#elif defined(_WIN32) or defined(_WIN64)
#include <gl/gl3w.h>
#elif defined(__APPLE__)
#include <OpenGL/gl3.h>
#endif

#ifndef NULL
#define NULL 0
#endif

class OpenGLAgent
{
public:
    OpenGLAgent();
    virtual ~OpenGLAgent();

    void PrepareOpenGL();
    void ShowGLVersion();

protected:

public:
    GLuint shaderProgram;
    //GLuint vertexArrayObject;
    //GLuint vertexBuffer;

    GLint projectionMat;
    GLint colourAttribute;
    GLint positionAttribute;
};

extern OpenGLAgent openglAgent;

#endif // OPENGLAGENT_H
