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

    bool getPosition(const Coordinate coordinate) {
        return maze->at(coordinate.y)->at(coordinate.x);
    }

    void setPosition(const  Coordinate coordinate, bool value) {
        maze->at(coordinate.y)->at(coordinate.x) = value;
    }

    int getHeight(){
        return height;
    }

    int getWidth(){
        return width;
    }

};

#endif //GRP04_ALGDATII_STRUCTS_H
