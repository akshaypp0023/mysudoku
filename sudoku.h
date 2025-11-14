#ifndef SUDOKU_H
#define SUDOKU_H

#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class sudoku
{
public:
    int grid[9][9];
    bool fixedCell[9][9];

    sudoku();                 // constructor
    bool valid(int row, int col, int num);
    void insert(int row, int col, int num);
    void generate_initial_numbers();
    bool isCompletedCorrect();
};

#endif
