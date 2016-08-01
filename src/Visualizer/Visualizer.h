//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_VISUALIZER_H
#define GRP04_ALGDATII_VISUALIZER_H

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <stdio.h>
#include <list>
#include "../Structs/Structs.h"

class Visualizer {

public:
    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The surface contained by the window
    SDL_Surface *gScreenSurface = NULL;
    SDL_Thread *pathThread = NULL;

    Maze *maze;
    list<Maze::Coordinate> *coordinates;
    Maze::Coordinate *start;
    Maze::Coordinate *end;

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
    // Color of entry and exit
    Uint32 cDoor;
    // Color of the calculated path
    Uint32 cPath;

    bool init();

    void drawWalls();

    void drawWays();

    void drawDoors();

    void close();

    Visualizer(Maze *maze,
               list<Maze::Coordinate> *coordinates,
               Maze::Coordinate *start,
               Maze::Coordinate *end) : maze(maze), coordinates(coordinates), start(start), end(end) {
        ENTITY_SIZE = SCREEN_SIZE / max(maze->getHeight(), maze->getWidth());
    };

    void visualize();
};

#endif //GRP04_ALGDATII_VISUALIZER_H
