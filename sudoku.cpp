#include<iostream>
#include<algorithm>
#include"sudoku.h"
using namespace std;

//initialize
Sudoku::Sudoku() {
    for(int i=0; i<9; i++)for(int j=0; j<9; j++)data[i][j]=0,data2[i][j]=0;
    solvable = 0;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            map[i][j][0] = 9;
            for(int k=1; k<10; k++)map[i][j][k]=1;
        }
}

//io
void Sudoku::input() {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>data[i][j];
}

void Sudoku::output() {
    for(int i=0; i<9; i++) {
        cout<<data[i][0];
        for(int j=1; j<9; j++)cout<<" "<<data[i][j];
        cout<<endl;
    }
}

//generate
void Sudoku::generand(int x) {
    if(x==1) {
        data[0][3]=1, data[3][5]=1, data[5][8]=1;
        data[0][6]=2, data[2][1]=2, data[5][0]=2, data[7][8]=2, data[8][3]=2;
        data[0][2]=3, data[3][0]=3, data[7][4]=3, data[8][7]=3;
        data[1][4]=4, data[3][1]=4, data[4][7]=4, data[8][2]=4;
        data[3][4]=5, data[5][1]=5, data[7][0]=5;
        data[0][0]=6, data[6][3]=6;
        data[1][8]=7;
        data[2][5]=8, data[7][2]=8;
        data[2][6]=9, data[7][1]=9;
    } else if(x==2) {
        data[2][3]=1, data[3][1]=1, data[8][7]=1;
        data[2][6]=2, data[3][8]=2, data[7][4]=2;
        data[0][6]=3, data[4][7]=3, data[6][0]=3;
        data[2][8]=4, data[3][5]=4, data[6][1]=4;
        data[4][4]=5;
        data[1][1]=6, data[5][3]=6, data[6][4]=6, data[7][7]=6;
        data[0][3]=7, data[4][5]=7, data[7][6]=7, data[8][4]=7;
        data[0][1]=8, data[1][3]=8, data[5][0]=8;
        data[1][2]=9, data[7][5]=9;
    } else {
        data[2][1]=1, data[6][0]=1, data[7][3]=1;
        data[2][6]=3, data[3][3]=3, data[4][8]=3, data[7][0]=3;
        data[5][1]=4, data[7][2]=4;
        data[2][5]=5, data[3][4]=5, data[5][7]=5;
        data[0][0]=6, data[5][6]=6, data[7][5]=6;
        data[0][6]=7, data[1][4]=7, data[3][7]=7, data[4][3]=7, data[6][8]=7;
        data[1][5]=8, data[4][1]=8, data[7][6]=8;
        data[0][3]=9, data[1][8]=9, data[6][2]=9;
    }
}

void Sudoku::generate() {
}

//transform (finish: 0)
void Sudoku::swapNum(int x, int y) {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            if(data[i][j]==x) data[i][j]=y;
            else if(data[i][j]==y) data[i][j]=x;
        }
}

void Sudoku::swapRow(int x, int y) {
    for(int i=0; i<3; i++)
        for(int j=0; j<9; j++)
            swap(data[3*x+i][j], data[3*y+i][j]);
}

void Sudoku::swapCol(int x, int y) {
    for(int i=0; i<3; i++)
        for(int j=0; j<9; j++)
            swap(data[j][3*x+i], data[j][3*y+i]);
}

void Sudoku::flip(int x) {
    //up-down
    if(x==0) {
        for(int i=0; i<9; i++)
            for(int j=0; j<4; j++)
                swap(data[j][i], data[8-j][i]);
    }
    //left-right
    else if(x==1) {
        for(int i=0; i<9; i++)
            for(int j=0; j<4; j++)
                swap(data[i][j], data[i][8-j]);
    }
}

void Sudoku::rotate(int x) {
    x=x%4;
    if(x!=0) {
        for(int i=0; i<8; i++)
            for(int j=0; j<8-i; j++)
                swap(data[i][j], data[8-j][8-i]);

        if(x==1) flip(0);
        else if(x==3) flip(1);
        else if(x==2)
            for(int i=1; i<9; i++)
                for(int j=0; j<i; j++)
                    swap(data[i][j], data[j][i]);
    }
}

//solve
void Sudoku::getEnd() {
    for(int i=8; i>=0; i--) {
        for(int j=8; j>=0; j--) {
            if(data[i][j]==0) {
                end = 9*i+j;
                break;
            }
        }
        if(end!=0)break;
    }
}

bool Sudoku::isPlace(int count) {
    int row = count / 9;
    int col = count % 9;

    for(int i = 0; i < 9; i++) {
        if(data[row][i] == data[row][col] && i != col) {
            return false;
        }
    }

    for(int i = 0; i < 9; i++) {
        if(data[i][col] == data[row][col] && i != row) {
            return false;
        }
    }

    int tempRow = row / 3 * 3;
    int tempCol = col / 3 * 3;
    for(int i = tempRow; i < tempRow + 3; i++) {
        for(int j = tempCol; j < tempCol + 3; j++) {
            if(data[i][j] == data[row][col] && i != row && j != col) {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::backtrace(int count) {
    /*if(count == 81){
        if(solvable == 0){
            for
        }
        cout<<"1"<<endl;
    	output();
        solvable = 1;
    	return;
    }*/
    int row = count / 9;
    int col = count % 9;
    if(data[row][col] == 0) {
        for(int i = 1; i <= 9; i++) {
            if(map[row][col][i]!=0) {
                data[row][col] = i;
                if(isPlace(count)) {
                    if(count==end) {
                        if(solvable ==0) {
                            solvable =1;
                            for(int j=0; j<9; j++)
                                for(int k=0; k<9; k++)
                                    data2[j][k]=data[j][k];
                        } else if(solvable ==1) {
                            solvable =2;
                            return;
                        }
                    } else backtrace(count+1);
                }
            }
        }
        data[row][col] = 0;
    } else backtrace(count+1);
}

void Sudoku::setMap() {
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(data[i][j]!=0){
                map[i][j][0]=-1;
                for(int k=1;k<10;k++)map[i][j][k]=0;
                for(int k=0;k<9;k++){
                    if(map[i][k][data[i][j]]!=0){
                        map[i][k][data[i][j]]=0;
                        map[i][k][0]--;
                    }
                    if(map[k][j][data[i][j]]!=0){
                        map[k][j][data[i][j]]=0;
                        map[k][j][0]--;
                    }
                }
                for(int k=i/3*3; k<i/3*3+3; k++)
                    for(int l=j/3*3; l<j/3*3+3; l++)
                        if(map[k][l][data[i][j]]!=0){
                            map[k][l][data[i][j]]=0;
                            map[k][l][0]--;
                        }
            }
        }
}

void Sudoku::eliminate(int x, int y, int n) {
    for(int i=0; i<9; i++) {
        if(map[x][i][n]!=0) {
            map[x][i][n]=0;
            map[x][i][0]--;
        }
        if(map[i][y][n]!=0) {
            map[i][y][n]=0;
            map[i][y][0]--;
        }
    }
    for(int i=x/3*3; i<x/3*3+3; i++)
        for(int j=y/3*3; j=y/3*3+3; j++)
            if(map[i][j][n]!=0) {
                map[i][j][n]=0;
                map[i][j][0]--;
            }
}

void Sudoku::constraint() {
    int check1=0;
    //
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(map[i][j][0]==1) {
                for(int k=1; k<=9; k++) {
                    if(map[i][j][k]==1) {
                        data[i][j]=k;
                        map[i][j][0]=-1;
                        for(int l=1; l<=9; l++)map[i][j][l]=0;
                        eliminate(i, j, k);
                        check1=1;
                        break;
                    }
                }
            }
    //if(check1==1)constraint();
    //else return;
    //
    /*for(int i=1;i<=9;i++){ //number going to be detected
        int col[9], row[9], grid[9];
        for(int j=0;j<9;j++)col[j]=0, row[j]=0, grid[j]=0;
     }*/












}
