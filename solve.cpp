#include<iostream>
#include"sudoku.h"
using namespace std;

int main() {
    Sudoku problem;
    problem.input();
    problem.setMap();
    problem.getEnd();

    //problem.constraint();

    problem.backtrace(0);

    if(problem.solvable==0) cout<<"0"<<endl;
    else if(problem.solvable==2) cout<<"2"<<endl;
    else {
        //cout<<problem.end<<endl;
        cout<<"1"<<endl;
        for(int i=0; i<9; i++) {
            cout<<problem.data2[i][0];
            for(int j=1; j<9; j++)cout<<" "<<problem.data2[i][j];
            cout<<endl;
        }
    }
    return 0;
}
