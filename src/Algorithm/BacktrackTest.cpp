//
// Created by Maximilian on 26.07.2016.
//
#include <iostream>
#include "../Structs/Structs.h"
#include <chrono>
#include "Backtracker.h"

using namespace std;

int main() {
    cout << "Started!" << endl;

    int size = 10000;

    Maze *maze = new Maze(size,size);

    for(int i = 0; i < maze->getHeight(); i++){
        for(int j = 0; j < maze->getWidth(); j++) {
            maze->setPosition(j,i,false);
        }
    }

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    Backtracker *bt = new Backtracker(maze);

    list<Maze::Coordinate> way = bt->solve(new Maze::Coordinate(1,1), new Maze::Coordinate(1,2));

    chrono::steady_clock::time_point end= chrono::steady_clock::now();

    cout << "Time difference s = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1000000.0 <<endl;


    /** Ausgabe Waypoints
    for(list<Maze::Coordinate>::iterator it = way.begin(); it != way.end(); it++){
        cout << "Waypoint: {" << it->x << "," << it->y << "} ";
    }
    **/

    cout << endl << "Waypointsize: " << way.size() << endl;

    cout << "Ended!!" << endl;



    return 0;
}