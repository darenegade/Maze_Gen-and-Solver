//
// Created by Maximilian on 26.07.2016.
//

#include "Backtracker.h"

bool Backtracker::solve(const Maze::Coordinate *end, list<Maze::Coordinate> *path) {
    const Maze::Coordinate *current = &path->back();

    // find next empty tile
    for(Maze::Coordinate *next = getNextEmptyNeighbour(current); next != nullptr; next = getNextEmptyNeighbour(current)) {
        // recursion with new step
        path->push_back(*next);
        if (solve(end, path)) {
            // found path
            return true;
        }

    }
    // backtrack
    path->pop_back();
    return false;
}

list<Maze::Coordinate> Backtracker::solve(const Maze::Coordinate *start, const Maze::Coordinate *end) {
    list<Maze::Coordinate> *path = new list<Maze::Coordinate>{1, *start};
    if(solve(end, path)){
        return *path;
    } else {
        return {};
    }
}

Maze::Coordinate* Backtracker::getNextEmptyNeighbour(const Maze::Coordinate *current){
    // right
    Maze::Coordinate *next = new Maze::Coordinate(current->x+1, current->y);
    if((current->x+1) < maze->getHeight() &&!maze->getPosition(next)){
        maze->setPosition(next, true);
        return next;
    }
    // bottom
    next = new Maze::Coordinate(current->x, current->y+1);
    if((current->y+1) < maze->getWidth() &&!maze->getPosition(next)){
        maze->setPosition(next, true);
        return next;
    }
    // left
    next = new Maze::Coordinate(current->x-1, current->y);
    if((current->x-1) >= 0 &&!maze->getPosition(next)){
        maze->setPosition(next, true);
        return next;
    }
    // bottom
    next = new Maze::Coordinate(current->x, current->y-1);
    if((current->y+1) <= 0 &&!maze->getPosition(next)){
        maze->setPosition(next, true);
        return next;
    }
    return nullptr;
}
