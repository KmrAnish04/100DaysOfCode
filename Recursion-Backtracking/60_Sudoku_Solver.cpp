// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/solve-sudoku-official/ojquestion
        nados: https://nados.io/question/solve-sudoku?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include <bits/stdc++.h>
using namespace std;

bool isNumSafeToPut(vector<vector<int>>board, int row, int col, int num){
    //Checking Row
    for(int i=0; i<9; i++){
        if(board[row][i]==num) return false;
    }
    
    //Checking Col
    for(int i=0; i<9; i++){
        if(board[i][col]==num) return false;
    }
    
    // Checking Sub-Matrix
    for(int i=(3*(row/3)); i<(3*(row/3)+3); i++){
        for(int j=(3*(col/3)); j<(3*(col/3)+3); j++){
            if(board[i][j]==num) return false;
        }
    }
    
    return true;
}

void sudukoSolver(vector<vector<int>>&board, int row, int col){
    if(row==board.size()){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    int nr;
    int nc;
    if(col==8){
        nr=row+1;
        nc=0;
    }
    else{
        nr=row; 
        nc=col+1;
    }
    if(board[row][col]==0){
        for(int i=1; i<=9; i++){
            if(isNumSafeToPut(board, row, col, i)){
                board[row][col]=i;
                sudukoSolver(board, nr, nc);
                board[row][col]=0;
            }
        }
    }
    else{
        sudukoSolver(board, nr, nc);
    }
}



int main(){
    vector<vector<int>> board(9, vector<int>(9));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int ele;
            cin>>ele;
            board[i][j]=ele;
        }
    }
    
    sudukoSolver(board, 0, 0);
    return 0;
}


