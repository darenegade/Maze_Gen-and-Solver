#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#ifdef main
# undef main
#endif /* main */
int main() {
    Maze* m = getDefaultLabyrinth();
    //Visualizer visualizer = *new Visualizer(m);
    //visualizer.visualize();
    return 0;
}