//
// Created by Fabian on 26.07.2016.
//

#ifndef GRP04_ALGDATII_VISUALIZER_H
#define GRP04_ALGDATII_VISUALIZER_H

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

class Visualizer {

private:
    //Screen dimension constants
    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;
    const int SCREEN_POS_X = 50;
    const int SCREEN_POS_Y = 50;


public:
    Visualizer(){};
    Visualizer(int width, int height): SCREEN_WIDTH(width), SCREEN_HEIGHT(height){}
    void visualize();
};

#endif //GRP04_ALGDATII_VISUALIZER_H
