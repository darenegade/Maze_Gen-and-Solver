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
    drawPath();
    drawDoors();

    //Update the surface
    SDL_UpdateWindowSurface(gWindow);

    //Main loop flag
    bool quit = false;
    //Event handler
    SDL_Event e;
    //While application is running
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
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

    cWall = SDL_MapRGBA(gScreenSurface->format, 153, 0, 0, 255);
    cWay = SDL_MapRGBA(gScreenSurface->format, 224, 224, 224, 255);
    cDoor = SDL_MapRGBA(gScreenSurface->format, 0, 0, 255, 255);
    cPath = SDL_MapRGBA(gScreenSurface->format, 102, 255, 102, 255);

    return success;
}

void Visualizer::close() {

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void Visualizer::drawWays() {
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

void Visualizer::drawWalls() {
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

void Visualizer::drawDoors() {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;

    rect.x = start->x * ENTITY_SIZE;
    rect.y = start->y * ENTITY_SIZE;
    SDL_FillRect(gScreenSurface, &rect, cDoor);
    rect.x = end->x * ENTITY_SIZE;
    rect.y = end->y * ENTITY_SIZE;
    SDL_FillRect(gScreenSurface, &rect, cDoor);
}

void Visualizer::drawPath() {
    SDL_Rect rect = *new SDL_Rect();
    rect.h = ENTITY_SIZE;
    rect.w = ENTITY_SIZE;
    Maze::Coordinate *coordinate;
    for (list<Maze::Coordinate>::iterator iterator = coordinates->begin(), end = coordinates->end();
         iterator != end; ++iterator) {
        coordinate = &*iterator;
        rect.x = coordinate->x * ENTITY_SIZE;
        rect.y = coordinate->y * ENTITY_SIZE;
        SDL_FillRect(gScreenSurface, &rect, cPath);
    }


}