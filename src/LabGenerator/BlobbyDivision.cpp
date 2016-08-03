//
// Created by René Zarwel on 01.08.16.
//

#include <cstdlib>
#include <random>
#include <iostream>
#include "BlobbyDivision.h"

void BlobbyDivision::generate(list<Cell *> *region, vector<vector<Cell>> *maze) {

    if (region->size() > 3) {

        //Prepare DataStructure
        list<Cell *> *a = new list<Cell *>();
        list<Cell *> *b = new list<Cell *>();
        list<Cell *> *sA = new list<Cell *>();
        list<Cell *> *sB = new list<Cell *>();

        //Select 2  seeds
        int n = (int) (rand() % region->size());
        std::list<Cell *>::iterator it = region->begin();
        std::advance(it, n);
        Cell *seed_a = *it;
        seed_a->state = Cell::A;
        a->push_back(seed_a);
        sA->push_back(seed_a);
        region->remove(seed_a);

        n = (int) (rand() % region->size());
        it = region->begin();
        std::advance(it, n);
        Cell *seed_b = *it;
        seed_b->state = Cell::B;
        b->push_back(seed_b);
        sB->push_back(seed_b);
        region->remove(seed_b);

        bool isB = false;
        list<Cell *> *currentSet;
        while (region->size() > 0) {

            if (isB) {
                currentSet = sB;
            } else {
                currentSet = sA;
            }

            //Get Random next seed
            if (currentSet->size() <= 0) {
                isB = !isB;
                continue;
            }

            n = (int) (rand() % currentSet->size());
            it = currentSet->begin();
            std::advance(it, n);
            Cell *current = *it;

            currentSet->remove(current);

            //find free neighbours and grow
            list<Cell *> *neighbours = getFreeNeighbours(current, region, maze);

            for (list<Cell *>::iterator it = neighbours->begin(); it != neighbours->end(); it++) {
                (*it)->state = (isB) ? Cell::B : Cell::A;
                currentSet->push_back(*it);
                region->remove(*it);

                if (isB) {
                    b->push_back(*it);
                } else {
                    a->push_back(*it);
                }
            }

            isB = !isB;
        }

        setWalls(a, b, maze);

        for (list<Cell *>::iterator it = a->begin(); it != a->end(); it++) {
            (*it)->state = Cell::UNSET;
        }

        for (list<Cell *>::iterator it = b->begin(); it != b->end(); it++) {
            (*it)->state = Cell::UNSET;
        }

        generate(a, maze);
        generate(b, maze);
    }

}

Maze *BlobbyDivision::generate(unsigned int n) {
    int size = 2 * n -1;
    srand(time(NULL));
    Maze *result = new Maze(size, size);
    vector<vector<Cell>> *maze = new vector<vector<Cell>>(n, vector<Cell>());
    list<Cell *> *region = new list<Cell *>();

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            maze->at(y).push_back(Cell(x, y));
        }
    }

    region->push_back(&(maze->at(0).at(0)));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            region->push_back(&maze->at(y).at(x));
        }
    }

    generate(region, maze);

    cout << "Generation finished!" << endl;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x < n - 1) {
                result->setPosition(x * 2 + 1, y * 2, maze->at(y).at(x).rightWall);
            }
            if (y < n - 1) {
                result->setPosition(x * 2, y * 2 + 1, maze->at(y).at(x).downWall);
            }
            if(x < n - 1 || y < n - 1) {
                result->setPosition(x * 2 + 1, y * 2 + 1, true);
            }
        }
    }

    return result;
}

list<BlobbyDivision::Cell *> *BlobbyDivision::getFreeNeighbours(BlobbyDivision::Cell *cell, list<Cell *> *region,
                                                                vector<vector<BlobbyDivision::Cell>> *maze) {

    list<BlobbyDivision::Cell *> *neighbours = new list<BlobbyDivision::Cell *>();
    Cell *next = cell;
    if ((cell->x + 1) < maze->at(0).size()) {
        next = &maze->at(cell->y).at(cell->x + 1);
        if (next->state == Cell::UNSET && std::find(region->begin(), region->end(), next) != region->end()) {
            neighbours->push_back(next);
        }
    }

    if ((cell->y + 1) < maze->size()) {
        next = &maze->at(cell->y + 1).at(cell->x);
        if (next->state == Cell::UNSET && std::find(region->begin(), region->end(), next) != region->end()) {
            neighbours->push_back(next);
        }
    }

    if ((cell->x - 1) >= 0) {
        next = &maze->at(cell->y).at(cell->x - 1);
        if (next->state == Cell::UNSET && std::find(region->begin(), region->end(), next) != region->end()) {
            neighbours->push_back(next);
        }
    }

    if ((cell->y - 1) >= 0) {
        next = &maze->at(cell->y - 1).at(cell->x);
        if (next->state == Cell::UNSET && std::find(region->begin(), region->end(), next) != region->end()) {
            neighbours->push_back(next);
        }
    }
    return neighbours;
}

void BlobbyDivision::setWalls(list<Cell *> *a, list<Cell *> *b,
                              vector<vector<BlobbyDivision::Cell>> *maze) {

    Cell *lastCell = nullptr;
    bool isDown = false;

    for (list<Cell *>::iterator it = a->begin(); it != a->end(); it++) {
        Cell *current = *it;
        Cell *next;

        if (current->x + 1 < maze->size()) {

            next = &maze->at(current->y).at(current->x + 1);

            if (std::find(b->begin(), b->end(), next) != b->end()) {
                current->rightWall = true;
                lastCell = current;
                isDown = false;
            }
        }

        if (current->y + 1 < maze->size()) {

            next = &maze->at(current->y + 1).at(current->x);

            if (std::find(b->begin(), b->end(), next) != b->end()) {
                current->downWall = true;
                lastCell = current;
                isDown = true;
            }
        }
    }

    for (list<Cell *>::iterator it = b->begin(); it != b->end(); it++) {
        Cell *current = *it;
        Cell *next;

        if (current->x + 1 < maze->size()) {
            next = &maze->at(current->y).at(current->x + 1);

            if (std::find(a->begin(), a->end(), next) != a->end()) {
                current->rightWall = true;
                lastCell = current;
                isDown = false;
            }
        }

        if (current->y + 1 < maze->size()) {
            next = &maze->at(current->y + 1).at(current->x);

            if (std::find(a->begin(), a->end(), next) != a->end()) {
                current->downWall = true;
                lastCell = current;
                isDown = true;
            }
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
