//
// Created by Maximilian on 26.07.2016.
//
#include <iostream>
#include "../Structs/Structs.h"
#include "Backtracker.h"

using namespace std;

int main() {
    cout << "Started!" << endl;

    int size = 300;

    Maze *maze = new Maze(size,size);

    for(int i = 0; i < maze->getHeight(); i++){
        for(int j = 0; j < maze->getWidth(); j++) {
            maze->setPosition(j,i,false);
        }
    }

    Backtracker *bt = new Backtracker(maze);

    list<Maze::Coordinate> way = bt->solve(new Maze::Coordinate(1,1), new Maze::Coordinate(size-1,1));

    cout << "Waypointsize: " << way.size() << endl;

    for(list<Maze::Coordinate>::iterator it = way.begin(); it != way.end(); it++){
        cout << "Waypoint: {" << it->x << "," << it->y << "}"<<endl;
    }

    cout << "Maze: " << endl;

    for(int i = 0; i < maze->getHeight(); i++){
        for(int j = 0; j < maze->getWidth(); j++) {
            cout << maze->getPosition(j,i);
        }
        cout<<endl;
    }

    cout << "Ended!!" << endl;



    return 0;
}