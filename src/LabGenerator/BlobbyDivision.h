//
// Created by René Zarwel on 01.08.16.
//

#ifndef GRP04_ALGDATII_BLOBBYDIVISION_H
#define GRP04_ALGDATII_BLOBBYDIVISION_H

#include <set>
#include "../Structs/Structs.h"

class BlobbyDivision {

private:
    struct Cell {
        const static int UNSET = 0;
        const static int A = 1;
        const static int B = 2;

        int x,y;
        int state = UNSET;
        bool rightWall, downWall;
        Cell(int x, int y){
            this->x = x;
            this->y = y;
        }
    };

    void generate(set<Cell*> *region, vector<vector<Cell>> *maze);
    set<Cell*> getFreeNeighbours(Cell* cell, set<Cell*> *region, vector<vector<Cell>> *maze);
    void setWalls(set<Cell*> *a,set<Cell*> *b, vector<vector<Cell>> *maze);

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end);

public:
    Maze generate(unsigned int n);

};


#endif //GRP04_ALGDATII_BLOBBYDIVISION_H
