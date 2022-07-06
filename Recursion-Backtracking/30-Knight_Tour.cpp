// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/online-java-foundation/recursion-backtracking/knights-tour-official/ojquestion
        nados: https://nados.io/question/knights-tour?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int r, int c, int move) {
  //write your code here
  int n=chess.size();
  if(r<0 || c<0 || r>=n || c>=n || chess[r][c]>0)return;
  else if(move==n*n){
      chess[r][c]=move;
      display(chess);
      chess[r][c]=0;
      return;
  }
  
  chess[r][c]=move;
  printKnightsTour(chess, r-2, c+1, move+1);
  printKnightsTour(chess, r-1, c+2, move+1);
  printKnightsTour(chess, r+1, c+2, move+1);
  printKnightsTour(chess, r+2, c+1, move+1);
  
  printKnightsTour(chess, r+2, c-1, move+1); 
  printKnightsTour(chess, r+1, c-2, move+1);
  printKnightsTour(chess, r-1, c-2, move+1); 
  printKnightsTour(chess, r-2, c-1, move+1); 
  chess[r][c]=0;
} 

int main() {
    int size;
    int r,c;
    cin>>size;
    cin>>r;
    cin>>c;
    vector<vector<int>> chess(size,vector<int>(size,0));
    printKnightsTour(chess, r, c, 1);
    return 0;
}