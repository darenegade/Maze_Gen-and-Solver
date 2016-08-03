#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {
    // Generate maze mit random algorithm
    //Maze *m = getRandomMaze();

    // Generate maze with recursive division
    Maze *m = getRandomMazeWithDivision(50,50);

    // Generate maze with recursive division and random wall placement
    //Maze *m = getRandomWallsMazeWithDivision(50,50);


    Visualizer visualizer = *new Visualizer(m);
    visualizer.visualize();


    return 0;
}