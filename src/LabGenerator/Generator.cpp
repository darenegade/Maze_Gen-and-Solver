//
// Created by Arne on 26.07.2016.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../Structs/Structs.h"

using namespace std;
static const int HEIGHT = 12;
static const int WIDTH = 12;

/**
 * Returns the static default Maze for an example
 * @return default maze
 */
static Maze * getDefaultLabyrinth(){
    Maze * maze = new Maze(HEIGHT,WIDTH);
    int test[HEIGHT][WIDTH] = {{1,1,1,1,1,0,1,1,1,1,1,1},
                               {1,0,0,0,0,0,0,0,0,0,0,1},
                               {1,0,1,1,1,1,1,1,1,0,1,1},
                               {1,0,1,0,0,0,0,0,1,0,0,1},
                               {1,0,1,0,1,1,1,0,1,1,0,1},
                               {1,0,0,0,1,0,0,0,1,0,0,1},
                               {1,1,1,1,1,1,1,0,1,0,1,1},
                               {1,0,0,0,0,0,1,0,1,1,1,1},
                               {1,0,1,0,1,0,0,0,0,1,0,1},
                               {1,0,1,0,1,1,1,0,1,1,0,1},
                               {1,0,1,0,0,0,0,0,0,0,0,1},
                               {1,1,1,0,1,1,1,1,1,1,1,1}};
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            maze->setPosition(coord, (bool)test[y][x]);
        }
    }
    return maze;
}

/**
 * Returns the static Maze where the edges are walls except for a start end point.
 * @return empty maze
 */
Maze * getMazeWithWalls(){
    int start = rand()%(WIDTH-2)+1;
    int end = rand()%(WIDTH-2)+1;
    Maze * maze = new Maze(HEIGHT,WIDTH);
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            bool foo = false;
            if((x == 0 || x == WIDTH-1)||(y == 0 && x != start)||(y == HEIGHT-1 && x != end)){
                foo = true;
            }
            maze->setPosition(coord, foo);
        }
    }
    return maze;
}

/**
 * Returns a complete random maze. There will be a solution to the maze
 * @return random maze
 */
Maze * getRandomMaze(){
    srand (time(NULL));
    int start = rand()%(WIDTH-2)+1;
    int end = rand()%(WIDTH-2)+1;
    Maze * maze = new Maze(HEIGHT,WIDTH);
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            bool foo = (bool)(rand()%2);
            if((x == 0 || x == WIDTH-1)||(y == 0 && x != start)||(y == HEIGHT-1 && x != end)){
                foo = true;
            } else if((y == 0 && x == start)||(y == HEIGHT-1 && x == end)){
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
    while(y != HEIGHT-2 && x != end){
        direction = rand()%4;
        switch (direction){
            case 0 : {
                if(y > 1) {
                    y--;
                    break;
                } else{
                    continue;
                }
            }
            case 1 : {
                if (x < WIDTH-2) {
                    x++;
                    break;
                } else {
                    continue;
                }
            }
            case 2 : {
                if (y < HEIGHT-2) {
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


