//
// Created by Arne on 26.07.2016.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../Structs/Structs.h"

using namespace std;
static const int HEIGHT = 50;
static const int WIDTH = 50;

/**
 * Returns the static default maze for an example.
 * @return default maze
 */
static Maze *getDefaultLabyrinth() {
    Maze *maze = new Maze(HEIGHT, WIDTH);
    int test[HEIGHT][WIDTH] = {{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
                               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                               {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                               {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                               {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                               {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                               {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
                               {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                               {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                               {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                               {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1}};
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            maze->setPosition(coord, (bool) test[y][x]);
        }
    }
    return maze;
}

/**
 * Returns the static maze in which the edges are walls except for the start end point.
 * @return empty maze
 */
Maze *getMazeWithWalls() {
    int start = rand() % (WIDTH - 2) + 1;
    int end = rand() % (WIDTH - 2) + 1;
    Maze *maze = new Maze(HEIGHT, WIDTH);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            bool foo = false;
            if ((x == 0 || x == WIDTH - 1) || (y == 0 && x != start) || (y == HEIGHT - 1 && x != end)) {
                foo = true;
            }
            maze->setPosition(coord, foo);
        }
    }
    return maze;
}

/**
 * Returns a complete random maze. There will be a solution to the maze.
 * @return random maze
 */
Maze *getRandomMaze() {
    srand(time(NULL));
    int start = rand() % (WIDTH - 2) + 1;
    int end = rand() % (WIDTH - 2) + 1;
    Maze *maze = new Maze(HEIGHT, WIDTH);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            bool foo = (bool) (rand() % 2);
            if ((x == 0 || x == WIDTH - 1) || (y == 0 && x != start) || (y == HEIGHT - 1 && x != end)) {
                foo = true;
            } else if ((y == 0 && x == start) || (y == HEIGHT - 1 && x == end)) {
                foo = false;
            }
            maze->setPosition(coord, foo);
        }
    }
    int x = start;
    int y = 1;
    int direction;
    Maze::Coordinate *coord = new Maze::Coordinate(x, y);
    maze->setPosition(coord, false);
    while (y != HEIGHT - 2 || x != end) {
        direction = rand() % 4;
        switch (direction) {
            case 0 : {
                if (y > 1) {
                    y--;
                    break;
                } else {
                    continue;
                }
            }
            case 1 : {
                if (x < WIDTH - 2) {
                    x++;
                    break;
                } else {
                    continue;
                }
            }
            case 2 : {
                if (y < HEIGHT - 2) {
                    y++;
                    break;
                } else {
                    continue;
                }
            }
            case 3 : {
                if (x > 1) {
                    x--;
                    break;
                } else {
                    continue;
                }
            }
        }
        Maze::Coordinate *coord = new Maze::Coordinate(x, y);
        maze->setPosition(coord, false);
    }
    return maze;
}

/**
 * Inserts a wall with a gap into the maze.
 * The wall will divide the given rectangle defined by leftUpper and rightLower (including both points).
 * If the rectangles height is bigger than it´s width, it will be divided horizontally, otherwise vertically.
 * After inserting the wall this method will be recursively called with both inner rectangles.
 * The Method returns if width or height is 2 or smaller.
 *
 * The rectangle is expected to be of odd width and hight for best results.
 *
 * @param maze the maze in which the wall shall be inserted
 * @param leftUpper the left upper coordinate of the rectangle to alter
 * @param rightLower the right lower coordinate of the rectangle to alter
 */
void innerMazePart(Maze *maze, Maze::Coordinate *leftUpper, Maze::Coordinate *rightLower, bool randomWalls) {
    int height = rightLower->y - leftUpper->y;
    int width = rightLower->x - leftUpper->x;
    if (height <= 1 || width <= 1) {
        return;
    }
    bool horizontal = height>width;

    if (horizontal) {
        int wall;
        if(randomWalls) {
            wall = (rand() % (height / 2)) * 2 + 1;
        } else {
            wall = height/2;
            if(wall%2==0){
                wall--;
            }
        }
        wall += leftUpper->y;

        int door = (rand() % (width / 2 + width % 2)) * 2 + leftUpper->x;
        for (int x = leftUpper->x; x <= rightLower->x; x++) {
            if (x != door) {
                maze->setPosition(x, wall, true);
            }
        }
        innerMazePart(maze, leftUpper, new Maze::Coordinate(rightLower->x, wall - 1), randomWalls);
        innerMazePart(maze, new Maze::Coordinate(leftUpper->x, wall + 1), rightLower, randomWalls);
    } else {
        int wall;
        if(randomWalls) {
            wall = (rand() % (width / 2)) * 2 + 1;
        } else {
            wall = width/2;
            if(wall%2==0){
                wall--;
            }
        }
        wall += leftUpper->x;

        int door = (rand() % (height / 2 + height % 2)) * 2 + leftUpper->y;
        for (int y = leftUpper->y; y <= rightLower->y; y++) {
            if (y != door) {
                maze->setPosition(wall, y, true);
            }
        }
        innerMazePart(maze, leftUpper, new Maze::Coordinate(wall - 1, rightLower->y), randomWalls);
        innerMazePart(maze, new Maze::Coordinate(wall + 1, leftUpper->y), rightLower, randomWalls);
    }
}

/**
 * Returns a randomly generated maze using the recursive division-algorithm.
 * For better results even numbers for width and height will be reduced by 1.
 * Walls will be dividing in half. Gaps will be random.
 *
 * @param width wanted width of the maze
 * @param height wanted height of the maze
 * @return the generated maze
 */
Maze *getRandomMazeWithDivision(int width, int height) {
    srand(time(NULL));
    if(width%2==0){
        width--;
    }
    if(height%2==0){
        height--;
    }

    Maze *maze = new Maze(height, width);
    innerMazePart(maze, new Maze::Coordinate(0, 0), new Maze::Coordinate(width - 1, height - 1), false);
    return maze;
}

/**
 * Returns a randomly generated maze using the recursive division-algorithm.
 * For better results even numbers for width and height will be reduced by 1.
 * Walls and gaps will be random;
 *
 * @param width wanted width of the maze
 * @param height wanted height of the maze
 * @return the generated maze
 */
Maze *getRandomWallsMazeWithDivision(int width, int height) {
    srand(time(NULL));
    if(width%2==0){
        width--;
    }
    if(height%2==0){
        height--;
    }

    Maze *maze = new Maze(height, width);
    innerMazePart(maze, new Maze::Coordinate(0, 0), new Maze::Coordinate(width - 1, height - 1), true);
    return maze;
}