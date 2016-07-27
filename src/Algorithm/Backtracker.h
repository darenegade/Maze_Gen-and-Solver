//
// Created by Maximilian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_BACKTRACKER_H
#define GRP04_ALGDATII_BACKTRACKER_H

#include <list>
#include "../Structs/Structs.h"

class Backtracker {
private:
    Maze *maze;
    Maze::Coordinate* getNextEmptyNeighbour(const Maze::Coordinate*);
    bool solve(const Maze::Coordinate*, list<Maze::Coordinate>*);
public:
    Backtracker(Maze* m) : maze(m){}

    list<Maze::Coordinate>* solve(const Maze::Coordinate*,const Maze::Coordinate*);
};


#endif //GRP04_ALGDATII_BACKTRACKER_H
