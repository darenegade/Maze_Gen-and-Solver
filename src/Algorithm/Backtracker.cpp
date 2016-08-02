//
// Created by Maximilian on 26.07.2016.
//

#include "Backtracker.h"

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
