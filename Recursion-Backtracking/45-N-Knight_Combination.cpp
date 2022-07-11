// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nknights-combinations-2das1d-knight-chooses-official/ojquestion
        nados: https://nados.io/question/nknights-combinations-2d-as-1d-knight-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

bool isCellSafe(vector<vector<int>>chess, int i, int j){
    if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2]==1) {
      return false;
    }

    if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1]==1) {
      return false;
    }

    if (i - 2 >= 0 && j + 1 < chess.size() && chess[i - 2][j + 1]==1) {
      return false;
    }

    if (i - 1 >= 0 && j + 2 < chess.size() && chess[i - 1][j + 2]==1) { 
      return false; 
    }

    return true;
}

void nknightComb(vector<vector<int>>&chess, int noOfKnts, int currKnt, int cell){
    
    if(currKnt==noOfKnts){
        for(int i=0; i<chess.size(); i++){
            for(int j=0; j<chess.size(); j++){
                if(chess[i][j]==1){
                    cout<<"k\t";
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
    
    for(int i=cell+1; i<chess.size()*chess.size(); i++){ 
        int row=i/noOfKnts; 
        int col=i%noOfKnts;
        if(chess[row][col]==0 && isCellSafe(chess, row, col)){
            chess[row][col]=1; 
            nknightComb(chess, noOfKnts, currKnt+1, row*chess.size()+col);
            chess[row][col]=0;
        }
    }
}


int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));
    nknightComb(chess, size, 0, -1);
    
    return 0;
}


