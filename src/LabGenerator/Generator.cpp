//
// Created by Arne on 26.07.2016.
//

#include <iostream>
#include "../Structs/Structs.h"
using namespace std;

static const int HEIGHT = 12;
static const int WIDTH = 12;

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
    for(int y; y < HEIGHT; y++){
        for(int x; x < WIDTH; x++){
            Maze::Coordinate *coord = new Maze::Coordinate(x, y);
            maze->setPosition(coord, test[y][x]);
        }
    }
    return maze;
}

int main() {
    cout << "hello" << endl;

    return 0;
}


