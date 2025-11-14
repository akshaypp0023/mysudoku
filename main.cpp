#include<iostream>
#include<ncurses.h> 
#include<cstdlib> 
#include<ctime> 
#include "sudoku.h"

using namespace std;



int main() {
    sudoku game;
    int row = 0, col = 0;

    // Initialize ncurses
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    // ---- NEW: COLOR INITIALIZATION ----
    start_color();
    use_default_colors();
    init_pair(1, COLOR_YELLOW, -1); // fixed cells
    init_pair(2, COLOR_CYAN,   -1); // user numbers
    init_pair(3, COLOR_GREEN,  -1); // correct message
    init_pair(4, COLOR_RED,    -1); // wrong message

    while (true) {
        clear();
        int screen_h, screen_w;
        getmaxyx(stdscr, screen_h, screen_w);

        // Board is 27 characters wide → center it
        int board_width = 27;
        int start_x = (screen_w - board_width) / 2;

        mvprintw(1, start_x, "SUDOKU");

        // ---- BOLD START ----
        attron(A_BOLD);

        printw("\n\nUse Arrow Keys | 1-9 Insert | c Check Sudoku | q Quit\n\n");

        // ------------------ draw 3x3 lines + color ------------------
        for (int i = 0; i < 9; i++) {

            if(i % 3 == 0)
                printw("------------------------\n");

            for (int j = 0; j < 9; j++) {

                if(j % 3 == 0)
                    printw("| ");

                // Highlight cursor
                if (i == row && j == col)
                    attron(A_REVERSE);

                // Apply colors
                if (game.fixedCell[i][j])
                    attron(COLOR_PAIR(1));  // yellow
                else if (game.grid[i][j] != 0)
                    attron(COLOR_PAIR(2));  // cyan

                printw("%d ", game.grid[i][j]);

                // Turn off color
                if (game.fixedCell[i][j])
                    attroff(COLOR_PAIR(1));
                else if (game.grid[i][j] != 0)
                    attroff(COLOR_PAIR(2));

                if (i == row && j == col)
                    attroff(A_REVERSE);
            }
            printw("|\n");
        }
        printw("------------------------\n");
        // ---------------------------------------------------------

        int ch = getch();
        if (ch == 'q') break;

        // ------------------ CHECK KEY ------------------
        if (ch == 'c')
        {
            if (game.isCompletedCorrect())
            {
                attron(COLOR_PAIR(3));
                printw("\n✔ SUDOKU COMPLETED CORRECTLY!\n");
                attroff(COLOR_PAIR(3));
            }
            else
            {
                attron(COLOR_PAIR(4));
                printw("\n✖ WRONG SOLUTION! Check again.\n");
                attroff(COLOR_PAIR(4));
            }
            getch();
            continue;
        }
        // ------------------------------------------------

        switch (ch) {
            case KEY_UP:    if (row > 0) row--; break;
            case KEY_DOWN:  if (row < 8) row++; break;
            case KEY_LEFT:  if (col > 0) col--; break;
            case KEY_RIGHT: if (col < 8) col++; break;

            default:
                if (ch >= '1' && ch <= '9') {
                    int num = ch - '0';
                    game.insert(row, col, num);
                }
                break;
        }
    }

    endwin();   // Restore terminal
    return 0;
}
