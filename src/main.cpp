#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {
    Maze::Coordinate *start;
    Maze::Coordinate *end;

    Maze *m = getRandomMazeWithDivision(320);
    start = new Maze::Coordinate(0, 0);
    end = new Maze::Coordinate(m->getHeight()-1, m->getHeight()-1);

    Backtracker *bt = new Backtracker(m);
    list<Maze::Coordinate> way = bt->solve(start, end);

    Visualizer visualizer = *new Visualizer(m, &way, start, end);
    visualizer.visualize();


    return 0;
}