#include<iostream>
#include<cstdlib>
#include<ctime>
#include"sudoku.h"
using namespace std;

int main() {
    Sudoku problem;
    srand(time(NULL));
    problem.generand(rand()%3+1); //1~3
    srand(time(NULL));
    int change=rand()%20+1;
    for(int i=0; i<change; i++) {
        srand(time(NULL));
        int temp = rand()%12+1; //1~12
        if(temp==1) {
            int a,b;
            while(1>0) {
                srand(time(NULL));
                a=rand()%9+1; //1~9
                srand(time(NULL));
                b=rand()%9+1; //1~9
                if(a!=b)break;
            }
            problem.swapNum(a, b);
        } else if(temp==2) problem.swapRow(0, 1);
        else if(temp==3) problem.swapRow(1, 2);
        else if(temp==4) problem.swapRow(0, 2);
        else if(temp==5) problem.swapCol(0, 1);
        else if(temp==6) problem.swapCol(1, 2);
        else if(temp==7) problem.swapCol(0, 2);
        else if(temp==8) problem.rotate(1);
        else if(temp==9) problem.rotate(2);
        else if(temp==10) problem.rotate(3);
        else if(temp==11) problem.flip(0);
        else if(temp==12) problem.flip(1);
    }

    problem.output();
    return 0;
}
