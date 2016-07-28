#include "Visualizer/Visualizer.h"
#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef main
# undef main
#endif /* main */

int main() {
    list<Maze::Coordinate> way = {};
    Maze::Coordinate *start;
    Maze::Coordinate *end;
    Maze *m = getRandomMaze();
    Backtracker *bt;
    while (way.empty()) {
        delete end, start, m, way, bt;
        m = getRandomMaze();

        for (int i = 0; i < m->getWidth(); i++) {
            if (!m->getPosition(i, 0)) {
                start = new Maze::Coordinate(i, 0);
            };
            if (!m->getPosition(i, m->getHeight() - 1)) {
                end = new Maze::Coordinate(i, m->getHeight() - 1);
            };
        }
        bt = new Backtracker(m);
        way = bt->solve(start, end);
    }
    Visualizer visualizer = *new Visualizer(m, &way, start, end);
    visualizer.visualize();


    return 0;
}