// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-combinations-2das1d-queen-chooses-official/ojquestion
        nados: https://nados.io/question/nqueens-combinations-2d-as-1d-queen-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include <bits/stdc++.h>
using namespace std;

bool isCellSafe(vector<vector<int>>&chess, int row, int col){
    //vectical up
    for(int i=row-1, j=col; i>=0; i--){
        if(chess[i][j]>0) return false;
    }
    
    //horizontal left
    for(int i=row, j=col-1; j>=0; j--){
        if(chess[i][j]>0) return false;
    }
    
    
    //daigonal up left
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(chess[i][j]>0) return false;
    }
    
    //daigonal up right
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){ 
        if(chess[i][j]>0) return false;
    } 
    
    return true;
}


void nQnsComb(vector<vector<int>> &chess, int noOfQns, int curQn, int preCell){
    if(curQn==noOfQns){
        for(int i=0; i<noOfQns; i++){
            for(int j=0; j<noOfQns; j++){
                if(chess[i][j]==1){
                    cout<<"q\t";
                }
                else{
                    cout<<"-\t";
                }
            } 
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i=preCell+1; i<noOfQns*noOfQns; i++){
        int row=i/noOfQns;
        int col=i%noOfQns; 
        if(isCellSafe(chess, row, col)){
            chess[row][col]=1;
            nQnsComb(chess, noOfQns, curQn+1, row*chess.size()+col);  
            chess[row][col]=0;
        }
    }
}


int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));
    nQnsComb(chess, size, 0, -1);
    
    return 0;
}



