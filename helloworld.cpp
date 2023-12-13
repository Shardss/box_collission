#include <iostream>

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Renderer3D.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

// a cube
vector<Point3D> points {Point3D{-1.0f, -1.0f, -1.0f}, Point3D{-1.0f, -1.0f,  1.0f},
                        Point3D{ 1.0f, -1.0f, -1.0f}, Point3D{-1.0f,  1.0f, -1.0f},
                        Point3D{-1.0f,  1.0f,  1.0f}, Point3D{ 1.0f, -1.0f,  1.0f},
                        Point3D{ 1.0f,  1.0f, -1.0f}, Point3D{ 1.0f,  1.0f,  1.0f}};

vector<Vertex> vertices {Vertex{0, 1}, Vertex{0, 2}, Vertex{0, 3},
                         Vertex{2, 5}, Vertex{3, 6}, Vertex{3, 4},
                         Vertex{4, 7}, Vertex{6, 7}, Vertex{7, 5},
                         Vertex{5, 1}, Vertex{4, 1}, Vertex{2, 6}};

int main( int argc, char* args[] )
{
    // std::cout << "Hello World!!!!" << std::endl;
    printf("Hello World!!!\n");

    // initialize window and renderer
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow("Cube renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    // create the renderer
    Renderer3D renderer3D(window, renderer, points, vertices);

    while(running)
    {
        if(SDL_QuitRequested())
            {running = false; break;}
        
        renderer3D.render();
    }

    return 0;
}