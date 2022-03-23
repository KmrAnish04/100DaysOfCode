/*
    Problem: Number of Islands
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
        Leetcode: https://leetcode.com/problems/number-of-islands/
        (GFG and Leetcode question are a bit different, in gfg we have to see daigonal elements also but not in 
         leetcode and rest all the logic is same.)

    Complexity Analysis:
        Expected Time Compelxity: O(n*m)
        Expected Space Compelxity: O(n*m)

        
    Algorithm:
        GFG Algorithm:
        The problem can be easily solved by applying DFS() on each component. 
        In each DFS() call, a component or a sub-graph is visited. We will call 
        DFS on the next un-visited component. The number of calls to DFS() gives 
        the number of connected components. BFS can also be used.
        Note: Keep in mind that you need to cover all the 8 neighbours (instead of 4 in normal case).

        Reference Solution video: https://www.youtube.com/watch?v=__98uL6wst8
    
*/


// GFG Solution
class Solution {
  public:
    // Function to find the number of islands.
    void dfsCheck(int i, int j, int row, int col, vector<vector<char>> &grid){
        grid[i][j]='2';
        
        if((i-1)>=0){
            if(grid[i-1][j]=='1'){
                dfsCheck(i-1, j, row, col, grid);
            }
        }
        if((j-1)>=0){
            if(grid[i][j-1]=='1'){
                dfsCheck(i, j-1, row, col, grid);
            }
        }
        if((i+1)<row){
            if(grid[i+1][j]=='1'){
                dfsCheck(i+1, j, row, col, grid);
            }
        }
        if((j+1)<col){
            if(grid[i][j+1]=='1'){
                dfsCheck(i, j+1, row, col, grid);
            }
        }
        
        // Daigonal Cases
        if((i-1)>=0 && (j-1)>=0){
            if(grid[i-1][j-1]=='1'){
                dfsCheck(i-1, j-1, row, col, grid);
            }
        }
        if((i-1)>=0 && (j+1)<col){
            if(grid[i-1][j+1]=='1'){
                dfsCheck(i-1, j+1, row, col, grid);
            }
        }
        if((i+1)<row && (j-1)>=0){
            if(grid[i+1][j-1]=='1'){
                dfsCheck(i+1, j-1, row, col, grid);
            }
        }
        if((i+1)<row && (j+1)<col){
            if(grid[i+1][j+1]=='1'){
                dfsCheck(i+1, j+1, row, col, grid);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfsCheck(i, j, row, col, grid);
                }
            }
        }
        
        return cnt;
    }
};


// Leetcode Solution
class Solution {
public:
    void dfsCheck(int i, int j, int row, int col, vector<vector<char>> &grid){
        grid[i][j]='2';
        
        if((i-1)>=0){
            if(grid[i-1][j]=='1'){
                dfsCheck(i-1, j, row, col, grid);
            }
        }
        if((j-1)>=0){
            if(grid[i][j-1]=='1'){
                dfsCheck(i, j-1, row, col, grid);
            }
        }
        if((i+1)<row){
            if(grid[i+1][j]=='1'){
                dfsCheck(i+1, j, row, col, grid);
            }
        }
        if((j+1)<col){
            if(grid[i][j+1]=='1'){
                dfsCheck(i, j+1, row, col, grid);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfsCheck(i, j, row, col, grid);
                }
            }
        }
        
        return cnt;
    }
};