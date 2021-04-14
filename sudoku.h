#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    Sudoku();

    //io
    void input();
    void output();

    // generate
    void generate();
    void generand(int x);

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    void getEnd();

    void backtrace(int count);
    bool isPlace(int count);

    void setMap();

    void constraint();
    void eliminate(int x, int y, int n);

    //data
    int data[9][9];
    int data2[9][9];
    int solvable;
    int map[9][9][10];
    int end;
};

#endif // SUDOKU_H
