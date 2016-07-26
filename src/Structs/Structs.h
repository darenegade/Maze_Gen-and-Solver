//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_STRUCTS_H
#define GRP04_ALGDATII_STRUCTS_H

#include <vector>

using namespace std;

class Maze {
private:
    vector<vector<bool>*>* maze;
    int height;
    int width;

    Maze(int height, int width): height(height), width(width) {
        maze = new vector(height, new vector<bool>(width));
    }

public:

    struct Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) : x(x), y(y) {}
    };

};

#endif //GRP04_ALGDATII_STRUCTS_H
