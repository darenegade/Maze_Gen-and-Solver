//
// Created by Maximilian on 26.07.2016.
//

#include "Backtracker.h"

bool Backtracker::solve(Maze::Coordinate *end, list<Maze::Coordinate> *path) {
    const Maze::Coordinate current = path->back();

    // find next empty tile
    for(Maze::Coordinate next = getNextEmptyNeighbour(current); next != nullptr; next = getNextEmptyNeighbour(current)) {
        // recursion with new step
        path->push_back(next);
        if (solve(end, path)) {
            // found path
            return true;
        }

    }
    // backtrack
    path->pop_back();
    return false;
}

list<Maze::Coordinate> Backtracker::solve(Maze::Coordinate *start, Maze::Coordinate *end) {
    list<Maze::Coordinate> path {start};
    if(solve(end, path)){
        return path;
    } else {
        return nullptr;
    }
}

Maze::Coordinate Backtracker::getNextEmptyNeighbour(Maze::Coordinate *current){
    // right
    const Maze::Coordinate next = new Maze::Coordinate(current->x+1, current->y);
    if(!maze->getPosition(next)){
        maze->setPosition(next, 1);
        return next;
    }
    // bottom
    const Maze::Coordinate next = new Maze::Coordinate(current->x, current->y+1);
    if(!maze->getPosition(next)){
        maze->setPosition(next, 1);
        return next;
    }
    // left
    const Maze::Coordinate next = new Maze::Coordinate(current->x-1, current->y);
    if(!maze->getPosition(next)){
        maze->setPosition(next, 1);
        return next;
    }
    // bottom
    const Maze::Coordinate next = new Maze::Coordinate(current->x, current->y-1);
    if(!maze->getPosition(next)){
        maze->setPosition(next, 1);
        return next;
    }
    return nullptr;
}
