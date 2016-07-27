//
// Created by Arne on 26.07.2016.
//

#include <iostream>
#include "../Structs/Structs.h"
using namespace std;

static const int HEIGHT = 12;
static const int WIDTH = 12;

/**
 * Returns the static default Maze for an example
 * @return default maze
 */
Maze * getDefaultLabirith(){
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


