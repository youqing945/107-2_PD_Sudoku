#include<iostream>
#include"sudoku.h"
using namespace std;

int main() {
    Sudoku problem;
    problem.input();
    while(1>0) {
        int mode;
        cin>>mode;
        if(mode<0||mode>5)cout<<"No such mode."<<endl;
        else if(mode==0)break;
        else {
            if(mode<=3) {
                int x, y;
                cin>>x>>y;
                if(mode==1) problem.swapNum(x, y);
                else if(mode==2) problem.swapRow(x, y);
                else if(mode==3) problem.swapCol(x, y);
            } else {
                int x;
                cin>>x;
                if(mode==4) problem.rotate(x);
                else if(mode==5) problem.flip(x);
            }
        }
    }
    problem.output();

    return 0;
}
