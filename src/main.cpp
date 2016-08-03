#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {
    Maze *m = getRandomMazeWithDivision(300, 300);

    Visualizer visualizer = *new Visualizer(m);
    visualizer.visualize();


    return 0;
}