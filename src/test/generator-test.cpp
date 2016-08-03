//
// Created by peter-mueller on 03.08.2016.
//

#include "gtest/gtest.h"
#include "../LabGenerator/BlobbyDivision.h"
#include "../LabGenerator/Generator.cpp"
#include "../Algorithm/Backtracker.h"

TEST(generator, test_maze_rnd_walls_solvable) {
    Maze *m = Generator::getRandomWallsMazeWithDivision(50, 50);
    Backtracker *b = new Backtracker(m);
    Maze::Coordinate *c = new Maze::Coordinate(0, 0);
    Maze::Coordinate *cc = new Maze::Coordinate(m->getHeight() - 1, m->getHeight() - 1);
    list <Maze::Coordinate> l = b->solve(c, cc);
    EXPECT_GT(l.size(), 0);
}

TEST(generator, test_maze_solvable) {
    Maze *m = Generator::getRandomMazeWithDivision(50, 50);
    Backtracker *b = new Backtracker(m);
    Maze::Coordinate *c = new Maze::Coordinate(0, 0);
    Maze::Coordinate *cc = new Maze::Coordinate(m->getHeight() - 1, m->getHeight() - 1);
    list <Maze::Coordinate> l = b->solve(c, cc);
    EXPECT_GT(l.size(), 0);
}

TEST(generator, test_maze_blobby_solvable) {
    Maze *m = BlobbyDivision::generate(50);
    Backtracker *b = new Backtracker(m);
    Maze::Coordinate *c = new Maze::Coordinate(0, 0);
    Maze::Coordinate *cc = new Maze::Coordinate(m->getHeight() - 1, m->getHeight() - 1);
    list <Maze::Coordinate> l = b->solve(c, cc);
    EXPECT_GT(l.size(), 0);
}

TEST(generator, test_maze_random_solvable) {
    Maze *m = Generator::getRandomMaze();
    Backtracker *b = new Backtracker(m);
    Maze::Coordinate *c = new Maze::Coordinate(0, 0);
    Maze::Coordinate *cc = new Maze::Coordinate(m->getHeight() - 1, m->getHeight() - 1);
    list <Maze::Coordinate> l = b->solve(c, cc);
    EXPECT_GT(l.size(), 0);
}