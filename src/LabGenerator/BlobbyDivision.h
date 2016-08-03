//
// Created by René Zarwel on 01.08.16.
//

#ifndef GRP04_ALGDATII_BLOBBYDIVISION_H
#define GRP04_ALGDATII_BLOBBYDIVISION_H

#include <list>
#include "../Structs/Structs.h"

class BlobbyDivision {

private:

    /**
     * A Cell of a Maze.
     */
    struct Cell {
        const static int UNSET = 0;
        const static int A = 1;
        const static int B = 2;

        int x, y;
        int state = UNSET;
        bool rightWall = false, downWall = false;

        Cell(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    /**
     * Recursive Blobby Devision Generator.
     *
     * @param region Cells to use
     * @param maze the whole maze
     */
    static void generate(list<Cell *> *region, vector<vector<Cell>> *maze);

    /**
     * Get the free neighbours of a cell.
     * @param cell to use
     * @param region to use
     * @param maze the whole maze
     * @return all free neighbours
     */
    static list<Cell *> *getFreeNeighbours(Cell *cell, list<Cell *> *region, vector<vector<Cell>> *maze);

    /**
     * Sets the walls between a and b.
     * @param a region A
     * @param b region B
     * @param maze the whole maze
     */
    static void setWalls(list<Cell *> *a, list<Cell *> *b, vector<vector<Cell>> *maze);

public:

    /**
     * Generates a maze.
     * @param n size of Maze
     * @return Maze
     */
    static Maze *generate(unsigned int n);

};


#endif //GRP04_ALGDATII_BLOBBYDIVISION_H
