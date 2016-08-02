//
// Created by René Zarwel on 01.08.16.
//

#include <cstdlib>
#include <random>
#include "BlobbyDivision.h"

void BlobbyDivision::generate(set<Cell*> *region, vector<vector<Cell>> *maze) {

    if (region->size() > 3) {

        set<Cell*> *a = new set();
        set<Cell*> *b = new set();
        set<Cell*> *s = new set();

        Cell *seed_a = *select_randomly(region->begin(), region->end());
        a->insert(seed_a);
        s->insert(seed_a);
        region->erase(seed_a);

        Cell *seed_b = *select_randomly(region->begin(), region->end());
        b->insert(seed_b);
        s->insert(seed_b);
        region->erase(seed_b);

        while (region->size() > 0) {

            //Get Random next seed to grow
            Cell* current = *select_randomly(s->begin(), s->end());
            s->erase(current);

            //find free neighbours and grow
            set<Cell*> neighbours = getFreeNeighbours(current,region,maze);

            set<Cell*> *currentSet;
            if(a->(current) != a->end()){
                currentSet = a;
            } else {
                currentSet = b;
            }

            currentSet->insert(neighbours.begin(), neighbours.end());
            s->insert(neighbours.begin(), neighbours.end());
            region->erase(neighbours.begin(), neighbours.end());

            delete neighbours;
            delete current;
        }


    }

}

Maze BlobbyDivision::generate(unsigned int n) {
    int size = 2 * n - 1;
    Maze *result = new Maze(size, size);
    vector<vector<Cell>> *maze = new vector(n, vector(n));
    set<Cell*> *region = new set();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Cell cell(i, j);

            region->insert(&cell);
            maze->at(i).at(j)=cell;
        }
    }

    generate(region, maze);

    return *result;
}

set<Cell *> BlobbyDivision::getFreeNeighbours(BlobbyDivision::Cell *cell, set<Cell *> *region,
                                             vector<vector<BlobbyDivision::Cell>> *maze) {
    return set<BlobbyDivision::Cell *>();
}

template<typename Iter>
Iter BlobbyDivision::select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, (int) (std::distance(start, end) - 1));
    std::advance(start, dis(gen));

    return start;
}
