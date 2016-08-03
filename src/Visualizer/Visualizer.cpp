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
    SDL_UpdateWindowSurface(gWindow);

    topRightThread = SDL_CreateThread(drawPath, "pathTopRight", this);
    bottomRightThread = SDL_CreateThread(drawPath, "pathBottomRight", this);
    bottomLeftThread = SDL_CreateThread(drawPath, "pathBottomLeft", this);

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
                                   SCREEN_SIZE,
                                   SCREEN_SIZE,
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

    cWall = SDL_MapRGBA(gScreenSurface->format, 0, 0, 0, 255);
    cWay = SDL_MapRGBA(gScreenSurface->format, 255, 255, 255, 255);

    return success;
}

void Visualizer::close() {

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_WaitThread(topRightThread, NULL);
    SDL_WaitThread(bottomLeftThread, NULL);
    SDL_WaitThread(bottomRightThread, NULL);

    SDL_DestroyMutex(mtx);

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

int Visualizer::drawPath(void *ptr) {
    Visualizer *visualizer = (Visualizer *) ptr;

    Maze::Coordinate *start = new Maze::Coordinate(0, 0);
    Maze::Coordinate *endPos;
    Uint32 cPath;

    if (SDL_GetThreadID(visualizer->topRightThread) == SDL_GetThreadID(NULL)) {
        // Finish is top right of the maze
        endPos = new Maze::Coordinate(visualizer->maze->getHeight() - 1, 0);
        cPath = SDL_MapRGBA(visualizer->gScreenSurface->format, 20, 35, 240, 255);
    } else if (SDL_GetThreadID(visualizer->bottomRightThread) == SDL_GetThreadID(NULL)) {
        // Finish is bottom right of the maze
        endPos = new Maze::Coordinate(visualizer->maze->getHeight() - 1, visualizer->maze->getHeight() - 1);
        cPath = SDL_MapRGBA(visualizer->gScreenSurface->format, 240, 35, 20, 255);
    } else if (SDL_GetThreadID(visualizer->bottomLeftThread) == SDL_GetThreadID(NULL)) {
        // Finish is bottom left of the maze
        endPos = new Maze::Coordinate(2, visualizer->maze->getHeight() - 1);
        cPath = SDL_MapRGBA(visualizer->gScreenSurface->format, 10, 120, 10, 255);
    }

    Backtracker *bt = new Backtracker(visualizer->maze);
    list<Maze::Coordinate> way = bt->solve(start, endPos);

    printf("Way has %d elements\n", way.size());

    SDL_Rect rect = *new SDL_Rect();
    rect.h = visualizer->ENTITY_SIZE;
    rect.w = visualizer->ENTITY_SIZE;
    Maze::Coordinate *coordinate;

    Uint32 delay = (Uint32) (2000 / sqrt(visualizer->maze->getHeight() * visualizer->maze->getWidth()));
    for (list<Maze::Coordinate>::iterator iterator =
            way.begin(),
                 end = way.end();
         iterator != end; ++iterator) {
        coordinate = &*iterator;
        rect.x = coordinate->x * visualizer->ENTITY_SIZE;
        rect.y = coordinate->y * visualizer->ENTITY_SIZE;

        SDL_LockMutex(visualizer->mtx);
        SDL_FillRect(visualizer->gScreenSurface, &rect, cPath);
        if (visualizer->gWindow != NULL) {
            //Update the surface
            SDL_UpdateWindowSurface(visualizer->gWindow);
            SDL_UnlockMutex(visualizer->mtx);
        } else {
            SDL_UnlockMutex(visualizer->mtx);
            break;
        }
        SDL_Delay(delay);
    }

    delete bt, way, start, endPos, cPath, coordinate, rect;

    return 0;
}