//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_STRUCTS_H
#define GRP04_ALGDATII_STRUCTS_H

#include <vector>

using namespace std;

class Maze {
private:
    vector<vector<bool>> maze;
    int height;
    int width;

public:

    Maze(const int height,const int width): height(height), width(width) {
        maze = vector<vector<bool>>(height, vector<bool>(width));
    }

    struct Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) : x(x), y(y) {}
    };

    bool getPosition(int x, int y){
        return maze.at(y).at(x);
    }

    bool getPosition(Coordinate * coordinate) {
        return maze.at(coordinate->y).at(coordinate->x);
    }

    void setPosition(Coordinate * coordinate, bool value) {
        maze.at(coordinate->y).at(coordinate->x) = value;
    }

    int getHeight(){
        return height;
    }

    int getWidth(){
        return width;
    }

};

#endif //GRP04_ALGDATII_STRUCTS_H
