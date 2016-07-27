//
// Created by Maximilian on 26.07.2016.
//
#include <iostream>
#include "../Structs/Structs.h"
#include "../LabGenerator/Generator.cpp"
#include "Backtracker.cpp"

int main() {
    std::cout << "Started!" << std::endl;

    Maze *maze = getDefaultLabirith();

    Backtracker *bt = new Backtracker(maze);

    bt->solve(new Maze::Coordinate(0,0), new Maze::Coordinate(0,4));

    std::cout << "Ended!!" << std::endl;

    return 0;
}