//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_STRUCTS_H
#define GRP04_ALGDATII_STRUCTS_H

#include <vector>

using namespace std;

class Maze {
private:
    vector<vector<bool>>* maze;
    int height;
    int width;

public:

    /*Maze(int height, int width): height(height), width(width) {
        maze = new vector<vector<bool>>(height, new vector<bool>(width));
    }*/

    Maze(vector<vector<bool>> vec): height(vec->size()), width(vec->front()->size()), maze(vec) {}

    struct Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) : x(x), y(y) {}
    };

    bool getPosition(int x, int y) {
        if(x<0 || y<0 || x>=width || y>=height){
            return 1;
        }
        return maze->at(y)->at(x);
    }

    void setPosition(int x, int y, bool value) {
        maze->at(y)->at(x) = value;
    }

    int getHeight(){
        return height;
    }

    int getWidth(){
        return width;
    }

};

#endif //GRP04_ALGDATII_STRUCTS_H
