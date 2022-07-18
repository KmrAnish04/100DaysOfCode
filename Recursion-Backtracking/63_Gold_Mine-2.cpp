// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/gold-mine-2-official/ojquestion
        nados: https://nados.io/question/gold-mine-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

bool isCellValid(vector<vector<int>>board, vector<vector<bool>>vis, int row, int col){
    
    if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]==0 || vis[row][col]==true){
        return false;
    }
    
    return true;
}


int findMax(vector<vector<int>>board, vector<vector<bool>>&vis, int row, int col){
    
    int max=board[row][col];
    vis[row][col]=true;
    //up 
    if(isCellValid(board, vis, row-1, col)){
        max+=findMax(board, vis, row-1, col);
    } 
    
    //down
    if(isCellValid(board, vis, row+1, col)){
        max+=findMax(board, vis, row+1, col);
    }
    
    // left
    if(isCellValid(board, vis, row, col-1)){
        max+=findMax(board, vis, row, col-1);
    }
    
    // right
    if(isCellValid(board, vis, row, col+1)){
        max+=findMax(board, vis, row, col+1);
    }
    
    return max;
}

void solve(vector<vector<int>>&board, int n, int m, int msf){
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int maxSum=INT_MIN;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]!=0 && vis[i][j]==false){
                maxSum=max(maxSum,findMax(board, vis, i, j));
            }
        }
    }
    
    cout<<maxSum; // The Answer
}

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m; 
    
    vector<vector<int>> board(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int ele;
            cin>>ele;
            board[i][j]=ele;
        }
    }
    
    solve(board, n, m, INT_MIN);

    return 0;
}


