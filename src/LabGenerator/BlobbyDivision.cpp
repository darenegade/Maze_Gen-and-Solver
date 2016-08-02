//
// Created by René Zarwel on 01.08.16.
//

#include <cstdlib>
#include <random>
#include "BlobbyDivision.h"

void BlobbyDivision::generate(set<Cell *> *region, vector<vector<Cell>> *maze) {

    if (region->size() > 3) {

        //Prepare DataStructure
        set<Cell *> *a = new set();
        set<Cell *> *b = new set();

        //Select 2  seeds
        Cell *seed_a = *select_randomly(region->begin(), region->end());
        seed_a->state = Cell::A;
        a->insert(seed_a);
        region->erase(seed_a);

        Cell *seed_b = *select_randomly(region->begin(), region->end());
        seed_b->state = Cell::B;
        b->insert(seed_b);
        region->erase(seed_b);

        bool isB = false;
        set<Cell *> *currentSet;
        while (region->size() > 0) {

            if (isB) {
                currentSet = b;
            } else {
                currentSet = a;
            }

            //Get Random next seed
            Cell *current = *select_randomly(currentSet->begin(), currentSet->end());

            //find free neighbours and grow
            set<Cell *> neighbours = getFreeNeighbours(current, region, maze);

            for (set<Cell *>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {
                Cell *c = *it;
                c->state = (isB) ? Cell::B : Cell::A;
            }

            currentSet->insert(neighbours.begin(), neighbours.end());
            region->erase(neighbours.begin(), neighbours.end());

            delete neighbours, current;
            isB = !isB;
        }

        setWalls(a, b, maze);

        delete region;

        generate(a, maze);
        generate(b, maze);
    }

}

Maze BlobbyDivision::generate(unsigned int n) {
    int size = 2 * n - 1;
    Maze *result = new Maze(size, size);
    vector<vector<Cell>> *maze = new vector(n, vector(n));
    set<Cell *> *region = new set();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Cell cell(i, j);

            region->insert(&cell);
            maze->at(i).at(j) = cell;
        }
    }

    generate(region, maze);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            result->setPosition(x*2+1,y*2,maze->at(x).at(y).rightWall);
            result->setPosition(x*2,y*2+1,maze->at(x).at(y).downWall);
            result->setPosition(x*2+1,y*2+1,true);
        }
    }

    return *result;
}

set<Cell *> BlobbyDivision::getFreeNeighbours(BlobbyDivision::Cell *cell, set<Cell *> *region,
                                              vector<vector<BlobbyDivision::Cell>> *maze) {

    set<Cell *> neighbours = set<BlobbyDivision::Cell *>();
    Cell next = maze->at(cell->y).at(cell->x + 1);
    if (next.state == Cell::UNSET && region->find(&next) != region->end()) {
        neighbours.insert(cell);
    }
    next = maze->at(cell->y + 1).at(cell->x);
    if (next.state == Cell::UNSET && region->find(&next) != region->end()) {
        neighbours.insert(cell);
    }
    next = maze->at(cell->y).at(cell->x - 1);
    if (next.state == Cell::UNSET && region->find(&next) != region->end()) {
        neighbours.insert(cell);
    }
    next = maze->at(cell->y - 1).at(cell->x);
    if (next.state == Cell::UNSET && region->find(&next) != region->end()) {
        neighbours.insert(cell);
    }

    return neighbours;
}

void BlobbyDivision::setWalls(set<Cell *> *a, set<Cell *> *b,
                              vector<vector<BlobbyDivision::Cell>> *maze) {

    Cell *lastCell = nullptr;
    bool isDown = false;

    for (set<Cell *>::iterator it = a->begin(); it != a->end(); it++) {
        Cell *current = *it;
        Cell next = maze->at(current->y).at(current->x + 1);

        if (b->find(&next) != b->end()) {
            current->rightWall = true;
            lastCell = current;
            isDown = false;
        }

        next = maze->at(current->y + 1).at(current->x);

        if (b->find(&next) != b->end()) {
            current->downWall = true;
            lastCell = current;
            isDown = true;
        }
    }

    for (set<Cell *>::iterator it = b->begin(); it != b->end(); it++) {
        Cell *current = *it;
        Cell next = maze->at(current->y).at(current->x + 1);

        if (a->find(&next) != a->end()) {
            current->rightWall = true;
            lastCell = current;
            isDown = false;
        }

        next = maze->at(current->y + 1).at(current->x);

        if (a->find(&next) != a->end()) {
            current->downWall = true;
            lastCell = current;
            isDown = true;
        }
    }
    if (lastCell != nullptr) {
        if (isDown) {
            lastCell->downWall = false;
        } else {
            lastCell->rightWall = false;
        }
    }

}

template<typename Iter>
Iter BlobbyDivision::select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, (int) (std::distance(start, end) - 1));
    std::advance(start, dis(gen));

    return start;
}
