#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "LabGenerator/BlobbyDivision.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {
    // Generate maze mit random algorithm
    //Maze *m = getRandomMaze();

    // Generate maze with recursive division
    //Maze *m = getRandomMazeWithDivision(105,105);

    // Generate maze with recursive division and random wall placement
    //Maze *m = getRandomWallsMazeWithDivision(105,105);

    // Generate maze with recursive division
    Maze *m = BlobbyDivision::generate(53);


    Visualizer visualizer = *new Visualizer(m);
    visualizer.visualize();


    return 0;
}