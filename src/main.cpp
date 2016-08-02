#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "LabGenerator/BlobbyDivision.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {

    Maze::Coordinate *start = new Maze::Coordinate(0,0);
    Maze* m = BlobbyDivision::generate(4);
    Maze::Coordinate *end = new Maze::Coordinate(m->getWidth()-2,m->getHeight()-2);
    Backtracker *bt = new Backtracker(m);
    list<Maze::Coordinate> way = bt->solve(start, end);


    Visualizer visualizer = *new Visualizer(m, &way, start, end);
    visualizer.visualize();


    return 0;
}