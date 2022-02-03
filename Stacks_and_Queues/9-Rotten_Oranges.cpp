/*
    Problem: Rotten Oranges
    Problem Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

    Complexity Analysis:
        Time: O(N*M)
        Space: O(N) 
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=-1;
        
        queue<pair<int,int>> que;
        int noOfFreshOrg=0;
        int noOfRottenOrg=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                    grid[i][j]=-1;
                    noOfRottenOrg++;
                }
                else if(grid[i][j]==1) noOfFreshOrg++;
            }
        }
        if(noOfFreshOrg==0) return 0;
        else if(noOfRottenOrg==0 && noOfFreshOrg!=0) return -1;
        else if(noOfRottenOrg!=0 && noOfFreshOrg==0) return 0;
        
        int orgRottenLater=0;
        while(!que.empty()){
            
            time++;
            int size=que.size();
            
            for(int p=0; p<size; p++){
                
                int i=que.front().first;
                int j=que.front().second;
                
                // up
                if(i-1>=0 and grid[i-1][j] ==1){
                    que.push({i-1,j});
                    grid[i-1][j]=-1;
                    orgRottenLater++;
                    
                }
                
                // down
                if(i+1<n and grid[i+1][j] ==1){
                    
                    que.push({i+1,j});
                    grid[i+1][j]=-1;
                    orgRottenLater++;
                }
                
                // left
                if(j-1>=0  and grid[i][j-1] ==1){
                    
                    que.push({i,j-1});
                    grid[i][j-1]=-1;
                    orgRottenLater++;
                }
                
                // right
                if(j+1<m  and grid[i][j+1] ==1){
                    
                    que.push({i,j+1});
                    grid[i][j+1]=-1;
                    orgRottenLater++;
                }
                
                que.pop();
            }
        }
        
        if(noOfFreshOrg!=orgRottenLater) return -1;
        
        return time;
    }
};