// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding:
        nados:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void nQnsBB(vector<vector<int>>&chess, int row, vector<bool>&cols, vector<bool>&nDaig, vector<bool>&revDaig, string asf){

    if(row==chess.size()){
        cout<<asf+"."<<endl;
        return;
    }

    for(int col=0; col<chess[0].size(); col++){
        if(!cols[col] && !nDaig[row+col] && !revDaig[row-col+chess.size()-1]){
            chess[row][col]=1;
            cols[col]=true;
            nDaig[row+col]=true;
            revDaig[row-col+chess.size()-1]=true;


            string rowStr=to_string(row);
            string colStr=to_string(col); 
            nQnsBB(chess, row+1, cols, nDaig, revDaig, asf+rowStr+"-"+colStr+", ");
            

            chess[row][col]=0;
            cols[col]=false;
            nDaig[row+col]=false;
            revDaig[row-col+chess.size()-1]=false;
        } 
    }
}  

int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size,0));
    vector<bool> cols(size, false);
    vector<bool> normDaig(2*size-1, false);
    vector<bool> revDiag(2*size-1, false);

    nQnsBB(chess, 0, cols, normDaig, revDiag, "");

    return 0;
}