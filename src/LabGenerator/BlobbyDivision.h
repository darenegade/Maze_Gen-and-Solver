//
// Created by René Zarwel on 01.08.16.
//

#ifndef GRP04_ALGDATII_BLOBBYDIVISION_H
#define GRP04_ALGDATII_BLOBBYDIVISION_H

#include <list>
#include "../Structs/Structs.h"

class BlobbyDivision {

private:
    struct Cell {
        const static int UNSET = 0;
        const static int A = 1;
        const static int B = 2;

        int x,y;
        int state = UNSET;
        bool rightWall = false, downWall = false;
        Cell(int x, int y){
            this->x = x;
            this->y = y;
        }
    };

    static void generate(list<Cell*> *region, vector<vector<Cell>> *maze);
    static list<Cell*>* getFreeNeighbours(Cell* cell, list<Cell*> *region, vector<vector<Cell>> *maze);
    static void setWalls(list<Cell*> *a,list<Cell*> *b, vector<vector<Cell>> *maze);

public:
    static Maze* generate(unsigned int n);

};


#endif //GRP04_ALGDATII_BLOBBYDIVISION_H
