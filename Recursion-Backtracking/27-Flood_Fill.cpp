// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/online-java-foundation/recursion-backtracking/flood-fill-official/ojquestion
        nados.io: https://nados.io/question/flood-fill?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



// Solution
#include<iostream>
#include<vector>
using namespace std;
// asf -> answer so far

bool isValidCell(int n, int m, int row, int col, vector<vector<int>> maze, vector<vector<int>> vis){
    if(row<0||col<0||row>=n||col>=m||maze[row][col]==1||vis[row][col]==1)
        return false;
    return true;
}

void floodfill(vector<vector<int>> maze, int sr, int sc, string asf, vector<vector<int>> &vis) {
    int n = maze.size();
    int m = maze[0].size();
    
    if(sr==n-1 && sc==m-1){
        cout<<asf<<endl;
        return;
    }
    
    vis[sr][sc]=1;
    vector<vector<int>> dir{ {-1,0}, {0,-1}, {1,0}, {0,1} }; //ordering={t,l,d,r}
    for(auto idx: dir){
        if( isValidCell(n, m, sr+idx[0], sc+idx[1], maze, vis) ) {
            if(idx==dir[0]){
                floodfill(maze, sr+idx[0], sc+idx[1], asf+"t", vis);
            }
            else if(idx==dir[1]){
                floodfill(maze, sr+idx[0], sc+idx[1], asf+"l", vis);
            }
            else if(idx==dir[2]){ 
                floodfill(maze, sr+idx[0], sc+idx[1], asf+"d", vis);
            }
            else if(idx==dir[3]){
                floodfill(maze, sr+idx[0], sc+idx[1], asf+"r", vis);
            } 
        }   
    } 
    vis[sr][sc]=0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
    
  vector<vector<int>> vis(n,vector<int>(m,0));
  floodfill(arr, 0, 0, "", vis);
}


// Code Ends