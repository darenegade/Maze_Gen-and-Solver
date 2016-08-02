#include "LabGenerator/Generator.cpp"
#include "Algorithm/Backtracker.h"

#ifdef consoleMain
# undef consoleMain
#endif /* consoleMain */

int main() {
    Maze::Coordinate *start;
    Maze::Coordinate *end;

    Maze *m = getRandomMazeWithDivision(110,30);

    start = new Maze::Coordinate(0, 0);
    end = new Maze::Coordinate(m->getWidth()-1, m->getHeight()-1);

    Backtracker *bt = new Backtracker(m);
    list<Maze::Coordinate> way = bt->solve(start, end);

    Maze *pathMaze = new Maze(m->getHeight(), m->getWidth());
    for (list<Maze::Coordinate>::iterator iterator =
            way.begin(),
                 end = way.end();
         iterator != end; ++iterator) {
        pathMaze->setPosition(&*iterator, true);
    }

    for (int y = -1; y <= m->getHeight(); y++) {
        for (int x = -1; x <= m->getWidth(); x++) {
            if (y < 0 || x < 0 || x >= m->getWidth() || y >= m->getHeight() || m->getPosition(x, y)) {
                cout << "X";
            } else if (pathMaze->getPosition(x, y)) {
                cout << "+";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}