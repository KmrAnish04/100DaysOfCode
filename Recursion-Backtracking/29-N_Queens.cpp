// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/online-java-foundation/recursion-backtracking/n-queens-official/ojquestion
        nados: https://nados.io/question/n-queens

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

bool isCellValid(vector<vector<int>>&arr, int row, int col){
    
    // vertical
    for(int i=row-1, j=col; i>=0; i--){
        if(arr[i][j]==1){
            return false;
        }
    } 
    
    // daigonal left
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(arr[i][j]==1){
            return false; 
        }
    }
    
    // daigonal right
    for(int i=row-1,j=col+1; i>=0 && j<arr.size(); i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    
    return true;
}

void printNQueens(vector<vector<int>>&chess, string qsf, int row) {
  //write your code here
  int n=chess.size();
  if(row==n){ 
      cout<<qsf+"."<<endl;
      return;
  }
   
   
  for(int i=0; i<n; i++){
      if(isCellValid(chess, row, i)==true){
          string rowS = to_string(row);
          string colS = to_string(i);
          chess[row][i]==1;
          printNQueens(chess, qsf+rowS+"-"+colS+", ", row+1);
          chess[row][i]==0;
      }
  }  

}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n,0));

  printNQueens(chess, "", 0);

}

