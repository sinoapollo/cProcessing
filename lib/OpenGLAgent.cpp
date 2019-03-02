//
//  OpenGLAgent.cpp
//  Processing
//
//  Created by 中国美术学院 陈天翼(Apollo Chen) on 1/28/19.
//  Copyright © 2019 Apollo Chen. All rights reserved.
//

#include "OpenGLAgent.h"

OpenGLAgent openglAgent;

OpenGLAgent::OpenGLAgent()
{
    //ctor
}

OpenGLAgent::~OpenGLAgent()
{
}

void OpenGLAgent::PrepareOpenGL()
{
    GLuint  vs;
    GLuint  fs;
    const char    *vss="#version 150\n\
    uniform mat4 projection;\
    in vec4 position;\
    in vec4 colour;\
    out vec4 colourV;\
    void main (void)\
    {\
    colourV = colour;\
    gl_Position =  projection * position;\
    }";
    const char    *fss="#version 150\n\
    in vec4 colourV;\
    out vec4 fragColour;\
    void main(void)\
    {\
    fragColour = colourV;\
    }";
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vss, NULL);
    glCompileShader(vs);
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fss, NULL);
    glCompileShader(fs);

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vs);
    glAttachShader(this->shaderProgram, fs);
    glBindFragDataLocation(this->shaderProgram, 0, "fragColour");
    glLinkProgram(this->shaderProgram);

    this->projectionMat = glGetUniformLocation(this->shaderProgram, "projection");
    this->colourAttribute = glGetAttribLocation(this->shaderProgram, "colour");
    this->positionAttribute = glGetAttribLocation(this->shaderProgram, "position");
    glDeleteShader(vs);
    glDeleteShader(fs);

    glUseProgram(this->shaderProgram);

}

void OpenGLAgent::ShowGLVersion() {
    const GLubyte *version = glGetString( GL_VERSION );
    const GLubyte *glslVersion = glGetString( GL_SHADING_LANGUAGE_VERSION );

    //printf("GL Version : %s", version);
    //printf("GLSL Version : %s", glslVersion);
}

