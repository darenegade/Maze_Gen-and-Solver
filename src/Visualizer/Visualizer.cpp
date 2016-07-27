//
// Created by Fabian on 26.07.2016.
//

#include <iostream>
#include "Visualizer.h"

using namespace std;

void Visualizer::visualize() {
    if (!init()) {
        printf("Error initializing Windows");
        exit(EXIT_FAILURE);
    };

    drawWalls();
    drawWays();
    drawDoors();
    drawPath();

    //Update the surface
    SDL_UpdateWindowSurface(gWindow);
    SDL_Delay(2000);
    close();
}

bool Visualizer::init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        //Create window
        gWindow = SDL_CreateWindow("Maze Solver",
                                   SCREEN_POS_X,
                                   SCREEN_POS_Y,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

void Visualizer::close() {

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void Visualizer::drawWays(Maze *maze) {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;
    for (int i = 0; i < maze->getHeight(); i++) {
        for (int j = 0; j < maze->getWidth(); j++) {
            if (!(maze->getPosition(i, j))) {
                rect.x = i * ENTITY_SIZE;
                rect.y = j * ENTITY_SIZE;
                SDL_FillRect(gScreenSurface,
                             &rect,
                             cWay);
            }
        }
    }
}

void Visualizer::drawWalls(Maze *maze) {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;
    for (int i = 0; i < maze->getHeight(); i++) {
        for (int j = 0; j < maze->getWidth(); j++) {
            if (maze->getPosition(i, j)) {
                rect.x = i * ENTITY_SIZE;
                rect.y = j * ENTITY_SIZE;
                SDL_FillRect(gScreenSurface,
                             &rect,
                             cWall);
            }
        }
    }
}

void Visualizer::drawDoors(Maze::Coordinate *entry, Maze::Coordinate *exit) {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;

    rect.x = entry->x;
    rect.y = entry->y;
    SDL_FillRect(gScreenSurface, &rect, cDoor);
    rect.x = exit->x;
    rect.y = exit->y;
    SDL_FillRect(gScreenSurface, &rect, cDoor);
}

void Visualizer::drawPath(list<Maze::Coordinate> coords) {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;
    Maze::Coordinate *coordinate;
    for (list<Maze::Coordinate>::iterator iterator = coords.begin(), end = coords.end(); iterator != end; ++iterator) {
        coordinate = &*iterator;
        rect.x = coordinate->x;
        rect.y = coordinate->y;
        SDL_FillRect(gScreenSurface, &rect, cPath);
    }


}