#pragma once
//Using SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <cmath>
#include <chrono>
#include <vector>
#include <SDL2/SDL_opengl.h>
#include <GL/glut.h>

// #define SHADED_CUBE

using namespace std;

class GL_Cube
{
    public:
        void reposition(float x, float y, float z);
        void drawCube();
        void hasDied(bool isDead);

        int* getMinMaxX();
        int* getMinMaxY();
        int* getMinMaxZ();
        GLfloat cube[8][3]=
        {
        {0,0,-50},   {50,0,-50},  {50,50,-50}, {0,50,-50},    // back face
        {0,0,0},     {50,0,0},    {50,50,0},   { 0,50,0}       // front face
        };

        bool isDead=false;
    private:
        GLfloat colorBuff[6][3] = {
            {1.0, 1.0, 0.0},
            {1.0, 0.0, 1.0},
            {0.0, 0.0, 1.0},
            {0.0, 1.0, 0.0},
            {0.0, 1.0, 1.0},
            {1.0, 0.0, 0.0},
        };

        GLfloat color[6][3] = {
            {1.0, 1.0, 0.0},
            {1.0, 0.0, 1.0},
            {0.0, 0.0, 1.0},
            {0.0, 1.0, 0.0},
            {0.0, 1.0, 1.0},
            {1.0, 0.0, 0.0},
        };

        GLfloat colorDead[6][3] = {
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.0},
        };

        // We use a short int max and min vals as a starting point to prevent eronneous checking later on
        int minMaxX[2] = {32767, -32767};        // 1st val: min
        int minMaxY[2] = {32767, -32767};        // 2nd val: max
        int minMaxZ[2] = {32767, -32767};


};