#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */
int main() {
    Maze* m = getDefaultLabyrinth();

    Backtracker *bt = new Backtracker(m);
    Maze::Coordinate *start = new Maze::Coordinate(5, 0);
    Maze::Coordinate *coordinate = new Maze::Coordinate(3, 11);
    list<Maze::Coordinate> way = bt->solve(start, coordinate);

    Visualizer visualizer = *new Visualizer(m, &way, start, coordinate);
    visualizer.visualize();
    return 0;
}