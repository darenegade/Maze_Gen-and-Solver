//
// Created by Maximilian on 26.07.2016.
//
#include <iostream>
#include "../Structs/Structs.h"
#include "../LabGenerator/Generator.cpp"
#include "Backtracker.cpp"

using namespace std;

int main() {
    cout << "Started!" << endl;

    Maze *maze = getDefaultLabirith();

    Backtracker *bt = new Backtracker(maze);

    list<Maze::Coordinate> way = bt->solve(new Maze::Coordinate(1,1), new Maze::Coordinate(10,10));

    cout << "Waypointsize: " << way.size() << endl;

    for(list<Maze::Coordinate>::iterator it = way.begin(); it != way.end(); it++){
        cout << "Waypoint: {" << it->x << "," << it->y << "}"<<endl;
    }

    cout << "Ended!!" << endl;

    return 0;
}