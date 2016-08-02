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
    Maze *original;

    /**
     * Returns the coordinates of an empty neighbor of the given coordinate. nullptr otherwise.
     * Right > Down > Left > Up
     * This method uses maze, not original.
     *
     * @param current base coordinate
     * @return empty neighbor of the givn coordinate nullptr otherwise.
     */
    Maze::Coordinate* getNextEmptyNeighbour(const Maze::Coordinate*);

    /**
     * Solves the maze.
     *
     * Looks for an empty neighbor next to the last coordinate in path, appends it to the path and sets the maze to true at that position.
     * When a dead end is reached elements are dropped from the end of path, until an alternate route is available.
     *
     * @param end coordinates of the target
     * @param path walked so far
     * @return true, if the end has been reached, false if a dead end was reached.
     */
    bool solve(const Maze::Coordinate*, list<Maze::Coordinate>*);
public:
    Backtracker(Maze* m) : original(m){}

    /**
     * Solves a maze using the backtrack-algorithm.
     *
     * @param start coordinates of the start
     * @param end coordinates of the target
     * @return a list of coordinates leading from start to end, if there is a solution. empty list for an impossible maze.
     */
    list<Maze::Coordinate> solve(Maze::Coordinate*, Maze::Coordinate*);
};


#endif //GRP04_ALGDATII_BACKTRACKER_H
