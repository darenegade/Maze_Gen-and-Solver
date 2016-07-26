//
// Created by Maximilian on 26.07.2016.
//
#include <iostream>
#include "../Structs/Structs.h"
#include "Backtracker.h"
#include <vector>

vector<vector<bool>> vec {{0,1,0,1,0},
                          {0,1,0,0,0},
                          {0,0,0,1,0},
                          {1,1,1,1,0},
                          {0,0,0,0,0}};
Maze* maze = new Maze(vec);
Backtracker *bt = new Backtracker(maze);

int main() {
    std::cout << "Started!" << std::endl;

    bt->solve(new Maze::Coordinate(0,0), new Maze::Coordinate(0,4));

    std::cout << "Ended!!" << std::endl;

    return 0;
}