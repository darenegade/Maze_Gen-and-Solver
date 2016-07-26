//
// Created by Maximilian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_BACKTRACKER_H
#define GRP04_ALGDATII_BACKTRACKER_H

#include <list>
#include "../Structs/Structs.h"

class Backtracker {
private:
    const Maze *maze;
    Maze::Coordinate getNextEmptyNeighbour(Maze::Coordinate*);
    bool solve(Maze::Coordinate*, list<Maze::Coordinate>*);
public:
    Backtracker(const Maze* m) : maze(m){}

    list<Maze::Coordinate> solve(Maze::Coordinate*, Maze::Coordinate*);
};


#endif //GRP04_ALGDATII_BACKTRACKER_H
