#include"sudoku.h"


  sudoku ::sudoku()
    {
      for(int i=0;i<9;i++)
      {
        for(int j=0;j<9;j++)
        {
            grid[i][j]=0;
            fixedCell[i][j]=false;
        }
      }

      generate_initial_numbers(); // NEW
    }

    bool sudoku::valid(int row,int col,int num)
    {
        //check row
        for(int j = 0; j < 9;j++)
           {
              if(grid[row][j]==num)
                 return false;
           }
        //check col
         for(int i = 0; i < 9; i++)
         {
            if(grid[i][col]==num)
              return false;
         }
        //3x3 subgrid check
         int startrow = row - row % 3;
         int startcol = col - col % 3;   // FIXED BUG

         for(int i = 0; i < 3; i++)
           {
            for (int j = 0; j < 3; j++)
             {
                if(grid[startrow+i][startcol+j]==num)
                   return false;
             }
           }
           return true;
    }

    void sudoku::insert(int row,int col,int num)
    {
        if(fixedCell[row][col])  // NEW
        {
            printw("Cannot modify fixed cell\n");
            return;
        }

        if(row<0 || row>8 || col<0 || col>8)
             return;
        if(num<1 ||num>9)
           return;
        
        if(valid(row,col,num))
          grid[row][col]=num;
        else
        {
            printw("invalid move\n");
        }
    }

    // NEW FUNCTION — adds random cells initially
    void sudoku::generate_initial_numbers()
    {
        srand(time(NULL));
        int fill_count = 20; // how many numbers to prefill

        while(fill_count > 0)
        {
            int r = rand() % 9;
            int c = rand() % 9;
            int n = (rand() % 9) + 1;

            if(grid[r][c] == 0 && valid(r,c,n))
            {
                grid[r][c] = n;
                fixedCell[r][c] = true; // lock it
                fill_count--;
            }
        }
    }
bool sudoku::isCompletedCorrect()
{
    // Check no zeros
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (grid[i][j] == 0)
            {
                return false;
            }
        }
    }

    // Check each placement
    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            int num = grid[r][c];

            grid[r][c] = 0;

            if (!valid(r, c, num))
            {
                grid[r][c] = num;
                return false;
            }

            grid[r][c] = num;
        }
    }

    return true;
}
