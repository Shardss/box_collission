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


using namespace std;

class GL_Cube
{
    public:
        void reposition(float x, float y, float z);
        void drawCube();
        int* getMinMaxX();
        int* getMinMaxY();
        int* getMinMaxZ();
        GLfloat cube[8][3]=
        {
        {10,10,-50}, {60,10,-50}, {60,60,-50}, {10,60,-50},    // back face
        {0,0,0},     {50,0,0},    {50,50,0},   { 0,50,0}       // front face
        };
    private:
        GLfloat color[6][3] = {
            {1.0, 1.0, 0.0},
            {1.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
            {0.0, 1.0, 0.0},
            {0.0, 1.0, 1.0},
            {1.0, 0.0, 0.0},
        };

        int minMaxX[2] = {32767, -32767};        // 1st val: min (we use a short int max as a starting point to prevent eronneous checking)
        int minMaxY[2] = {32767, -32767};        // 2nd val: max
        int minMaxZ[2] = {32767, -32767};


};