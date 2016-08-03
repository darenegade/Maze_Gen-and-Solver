//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_VISUALIZER_H
#define GRP04_ALGDATII_VISUALIZER_H

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_thread.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include "../Structs/Structs.h"
#include "../Algorithm/Backtracker.h"

/**
 * Visualizes the generated maze and the possible solutions
 */
class Visualizer {

public:
    /**
     * Used to synchronize the path-drawing threads to prevent deleted drawing operations.
     */
    SDL_mutex *mtx = SDL_CreateMutex();

    /**
     * The window to get rendered on.
     */
    SDL_Window *gWindow = NULL;

    /**
     * The surface contained by the window.
     */
    SDL_Surface *gScreenSurface = NULL;

    /**
     * Drawing thread that draws the path with the top right corner marked as exit.
     */
    SDL_Thread *topRightThread = NULL;

    /**
     * Drawing thread that draws the path with the bottom left corner marked as exit.
     */
    SDL_Thread *bottomLeftThread = NULL;

    /**
     * Drawing thread that draws the path with the bottom right corner marked as exit.
     */
    SDL_Thread *bottomRightThread = NULL;

    /**
     * The maze that gets visualized.
     */
    Maze *maze;

    /**
     * Size of the window in pixels. The window is always square.
     */
    int SCREEN_SIZE = 640;

    /**
     * x-Position of the window in pixels.
     */
    const int SCREEN_POS_X = 50;

    /**
     * y-position of the window in pixels.
     */
    const int SCREEN_POS_Y = 50;

    /**
     * Size in pixels of the entities. Entities are walls, ways and paths.
     */
    int ENTITY_SIZE;

    /**
     * Color of the wall.
     */
    Uint32 cWall;

    /**
     * Color of the Ways.
     */
    Uint32 cWay;

    /**
     * Initialization method. Creates, configures and shows the window.
     * @return true, if the initialization was succsessfull.
     */
    bool init();

    /**
     * Method to draw the walls of the maze.
     */
    void drawWalls();

    /**
     * Method to draw the ways of the maze.
     */
    void drawWays();

    /**
     * SDL_Thread function to draw the solution of the maze in a seperate thread.
     * @param ptr Pointer to the visualizer instance in which the path should be shown.
     * @return the status code of this thread.
     */
    static int drawPath(void *ptr);

    /**
     * Closes the window and destroys all used pointers, surfaces etc.
     */
    void close();

    /**
     * Constructor of the Visualizer
     * @param maze Maze to get visualized.
     * @return Visualizer to visualize the maze.
     */
    Visualizer(Maze *maze) : maze(maze) {
        ENTITY_SIZE = SCREEN_SIZE / max(maze->getHeight(), maze->getWidth());
    };

    /**
     * Starts the visualization of the maze and kicks of the three path-drawing threads to show the solution.
     */
    void visualize();
};

#endif //GRP04_ALGDATII_VISUALIZER_H
