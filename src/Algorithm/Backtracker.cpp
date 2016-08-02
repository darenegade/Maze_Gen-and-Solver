//
// Created by Maximilian on 26.07.2016.
//

#include "Backtracker.h"

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
bool Backtracker::solve(const Maze::Coordinate *end, list<Maze::Coordinate> *path) {

    // find next empty tile
    for(Maze::Coordinate *next = getNextEmptyNeighbour(&path->back()); next != nullptr; next = getNextEmptyNeighbour(&path->back())) {

        //new step
        maze->setPosition(next, true);
        path->push_back(*next);

        if ((next->y == end->y && next->x == end->x)) {
            // found path
            return true;
        }

        // backtrack
        for(next = getNextEmptyNeighbour(&path->back()); next == nullptr && path->size() > 0; next = getNextEmptyNeighbour(&path->back())) {
            path->pop_back();
        }
    }

    return false;
}

/**
 * Solves a maze using the backtrack-algorithm.
 *
 * @param start coordinates of the start
 * @param end coordinates of the target
 * @return a list of coordinates leading from start to end, if there is a solution. empty list for an impossible maze.
 */
list<Maze::Coordinate> Backtracker::solve(Maze::Coordinate *start, Maze::Coordinate *end) {
    list<Maze::Coordinate> *path = new list<Maze::Coordinate>{1, *start};

    maze = new Maze(*original);

    maze->setPosition(start,true);

    if(solve(end, path)){
        return *path;
    } else {
        return {};
    }
}

/**
 * Returns the coordinates of an empty neighbor of the given coordinate. nullptr otherwise.
 * Right > Down > Left > Up
 * This method uses maze, not original.
 *
 * @param current base coordinate
 * @return empty neighbor of the givn coordinate nullptr otherwise.
 */
Maze::Coordinate* Backtracker::getNextEmptyNeighbour(const Maze::Coordinate *current){
    // right
    Maze::Coordinate *next = new Maze::Coordinate(current->x+1, current->y);
    if(!maze->getPosition(next)){
        return next;
    }
    // bottom
    next = new Maze::Coordinate(current->x, current->y+1);
    if(!maze->getPosition(next)){
        return next;
    }
    // left
    next = new Maze::Coordinate(current->x-1, current->y);
    if(!maze->getPosition(next)){
        return next;
    }
    // bottom
    next = new Maze::Coordinate(current->x, current->y-1);
    if(!maze->getPosition(next)){
        return next;
    }
    return nullptr;
}
