//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_VISUALIZER_H
#define GRP04_ALGDATII_VISUALIZER_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <list>
#include "../Structs/Structs.h"

class Visualizer {

private:
    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The surface contained by the window
    SDL_Surface *gScreenSurface = NULL;

    //Screen dimension and position constants
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 1280;
    const int SCREEN_POS_X = 50;
    const int SCREEN_POS_Y = 50;

    // Entity Dimensions
    const int ENTITY_SIZE = 30;
    // Wall Color
    Uint32 cWall = SDL_MapRGBA(gScreenSurface->format, 153, 0, 0, 255);
    // Color of free paths
    Uint32 cWay = SDL_MapRGBA(gScreenSurface->format, 224, 224, 224, 255);
    // Color of entry and exit
    Uint32 cDoor = SDL_MapRGBA(gScreenSurface->format, 0, 0, 255, 255);
    // Color of the calculated path
    Uint32 cPath = SDL_MapRGBA(gScreenSurface->format, 102, 255, 102, 255);

    bool init();

    void drawWalls(Maze *maze);

    void drawWays(Maze *maze);

    void drawDoors(Maze::Coordinate *entry, Maze::Coordinate *exit);

    void drawPath(list<Maze::Coordinate> coords);

    void close();

public:
    Visualizer() {};

    Visualizer(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {}

    void visualize();
};

#endif //GRP04_ALGDATII_VISUALIZER_H
