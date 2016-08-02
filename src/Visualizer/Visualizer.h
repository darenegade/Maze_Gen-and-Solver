//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_VISUALIZER_H
#define GRP04_ALGDATII_VISUALIZER_H

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include "../Structs/Structs.h"
#include "../Algorithm/Backtracker.h"

class Visualizer {

public:
    SDL_mutex *mtx = SDL_CreateMutex();

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The surface contained by the window
    SDL_Surface *gScreenSurface = NULL;
    SDL_Thread *topRightThread = NULL;
    SDL_Thread *bottomLeftThread = NULL;
    SDL_Thread *bottomRightThread = NULL;

    Maze *maze;

    //Screen dimension and position constants
    int SCREEN_SIZE = 640;
    const int SCREEN_POS_X = 50;
    const int SCREEN_POS_Y = 50;

    // Entity Dimensions
    int ENTITY_SIZE = 30;
    // Wall Color
    Uint32 cWall;
    // Color of free paths
    Uint32 cWay;

    bool init();

    void drawWalls();

    void drawWays();

    void close();

    Visualizer(Maze *maze) : maze(maze) {
        ENTITY_SIZE = SCREEN_SIZE / max(maze->getHeight(), maze->getWidth());
    };

    void visualize();
};

#endif //GRP04_ALGDATII_VISUALIZER_H
