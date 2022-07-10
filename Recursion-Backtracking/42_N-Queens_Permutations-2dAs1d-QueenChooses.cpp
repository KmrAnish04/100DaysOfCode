// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-permutations-2das1d-official-queen-chooses/ojquestion
        nados: https://nados.io/question/nqueens-permutations-2d-as-1d-queen-chooses?zen=true

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
    //vectical down
    for(int i=row+1, j=col; i<chess.size(); i++){
        if(chess[i][j]>0) return false;
    }
    
    //horizontal left
    for(int i=row, j=col-1; j>=0; j--){
        if(chess[i][j]>0) return false;
    }
    //horizontal right
    for(int i=row, j=col+1; j<chess.size(); j++){
        if(chess[i][j]>0) return false;
    }
    
    //daigonal up left
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(chess[i][j]>0) return false;
    }
    //daigonal down left
    for(int i=row+1, j=col-1; i<chess.size() && j>=0; i++,j--){
        if(chess[i][j]>0) return false;
    }
    
    //daigonal up right
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){ 
        if(chess[i][j]>0) return false;
    } 
    
    //daigonal down right
    for(int i=row+1, j=col+1; i<chess.size() && j<chess.size(); i++,j++){
        if(chess[i][j]>0) return false;
    } 
    
    return true;
}


void nQnsPerm(vector<vector<int>>&chess, int noOfQns, int curQn){
    
    if(curQn>noOfQns){
        for(int i=0; i<noOfQns; i++){
            for(int j=0; j<noOfQns; j++){
                if(chess[i][j]>0){
                    string qnNum=to_string(chess[i][j]);
                    cout<<"q"+qnNum+"\t";
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
    
    
    for(int j=0; j<noOfQns*noOfQns; j++){ 
        int row=j/noOfQns;
        int col=j%noOfQns;
        if(chess[row][col]==0 && isCellSafe(chess, row, col)){ 
            chess[row][col]=curQn;
            nQnsPerm(chess, noOfQns, curQn+1); 
            chess[row][col]=0; 
        }  
    }
    
}



int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));
    
    nQnsPerm(chess, size, 1);
    return 0;
}


