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

    Maze(Maze &maze){
        this->maze = vector<vector<bool>>(maze.getHeight(), vector<bool>(maze.getWidth()));
        this->width = maze.getWidth();
        this->height = maze.getHeight();

        //Deep Copy of Maze
        for(int i = 0; i < maze.getHeight(); i++){
            for(int j = 0; j < maze.getWidth(); j++) {
                this->setPosition(j,i,maze.getPosition(j,i));
            }
        }
    }

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

    bool getPosition(int x, int y) {

        if(y < 0 || x < 0 ||
           x >= getWidth() || y >= getHeight()){
            return true;
        }

        return maze.at(y).at(x);
    }

    bool getPosition(Coordinate * coordinate) {

        if(coordinate->y < 0 || coordinate->x < 0 ||
                coordinate->x >= getWidth() || coordinate->y >= getHeight()){
            return true;
        }

        return maze.at(coordinate->y).at(coordinate->x);
    }

    void setPosition(int x, int y, bool value) {

        if(y < 0 || x < 0 ||
           x >= getWidth() || y >= getHeight()){
            return;
        }

        maze.at(y).at(x) = value;
    }

    void setPosition(Coordinate * coordinate, bool value) {
        if(coordinate->y < 0 || coordinate->x < 0 ||
           coordinate->x >= getWidth() || coordinate->y >= getHeight()){
            return;
        }

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
