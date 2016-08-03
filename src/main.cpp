#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "LabGenerator/BlobbyDivision.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {

    Maze::Coordinate *start = new Maze::Coordinate(0,0);
    Maze* m = BlobbyDivision::generate(100);
    Maze::Coordinate *end = new Maze::Coordinate(m->getWidth()-1,m->getHeight()-1);
    Backtracker *bt = new Backtracker(m);
    list<Maze::Coordinate> way = bt->solve(start, end);


    Visualizer visualizer = *new Visualizer(m, &way, start, end);
    visualizer.visualize();


    return 0;
}