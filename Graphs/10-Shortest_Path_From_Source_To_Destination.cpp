/*
    Problem: BFS traversal on directed Graph
    Question Link: 
        GFG:
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int ans=0;
        pair<int,int> desti={X,Y};
        // if(X==0 && Y==2) return -1;
        vector<vector<int>> vis(N, vector<int> (M, INT_MAX));
        queue<pair<pair<int,int>,int>> que;
        if(A[0][0]!=1){
            return -1;
        }
        else if(X==0 && Y==0) return 0;
        que.push({{0,0},0});
        vis[0][0]=0;
        A[0][0]=2;
        
        while(!que.empty()){
            pair<pair<int,int>,int> node = que.front();
            pair<int,int> currCell=node.first;
            if(currCell==desti) return vis[currCell.first][currCell.second];
            int nodeX=node.first.first;
            int nodeY=node.first.second;
            int cost=node.second;
            
            if(currCell!=desti && !que.empty()){
                // top
                if(nodeX-1>=0){
                    if(A[nodeX-1][nodeY]==1){
                        if(nodeX-1==X && nodeY==Y) return min(cost+1, vis[nodeX-1][nodeY]);
                        que.push({{nodeX-1,nodeY},cost+1});
                        vis[nodeX-1][nodeY]=min(cost+1, vis[nodeX-1][nodeY]);
                        A[nodeX-1][nodeY]==2;
                    }
                }
                // right
                if(nodeY+1<M){
                    if(A[nodeX][nodeY+1]==1){
                        if(nodeX==X && nodeY+1==Y) return min(cost+1, vis[nodeX][nodeY+1]);
                        que.push({{nodeX,nodeY+1}, cost+1});
                        vis[nodeX][nodeY+1]=min(cost+1, vis[nodeX][nodeY+1]);
                        A[nodeX][nodeY+1]==2;
                    }
                }
                // down
                if(nodeX+1<N){
                    if(A[nodeX+1][nodeY]==1){
                        if(nodeX+1==X && nodeY==Y) return min(cost+1, vis[nodeX+1][nodeY]);
                        que.push({{nodeX+1,nodeY},cost+1});
                        vis[nodeX+1][nodeY]=min(cost+1, vis[nodeX+1][nodeY]);
                        A[nodeX+1][nodeY]==2;
                    }
                }
                // left
                if(nodeY-1>=0){
                    if(A[nodeX][nodeY-1]==1){
                        if(nodeX==X && nodeY-1==Y) return min(cost+1, vis[nodeX][nodeY-1]);
                        que.push({{nodeX,nodeY-1}, cost+1});
                        vis[nodeX][nodeY-1]=min(cost+1, vis[nodeX][nodeY-1]);
                        A[nodeX][nodeY-1]==2;
                    }
                }
            }
            
            // A[nodeX][nodeY]=2;
            que.pop();
        }
        
        if(vis[X][Y]==INT_MAX) return -1;
        return vis[X][Y];
    }
};


class Solution {
  public:
    bool isSafe(int row, int col, int n, int m){
         if(row<0||col<0||row>n-1||col>m-1)
         return 0;
         return 1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int ans=0;
        pair<int,int> desti={X,Y};
        // if(X==0 && Y==2) return -1;
        vector<vector<int>> vis(N, vector<int> (M, INT_MAX));
        queue<pair<pair<int,int>,int>> que;
        if(A[0][0]!=1){
            return -1;
        }
        else if(X==0 && Y==0) return 0;
        que.push({{0,0},0});
        vis[0][0]=0;
        A[0][0]=2;
        
        while(!que.empty()){
            pair<pair<int,int>,int> node = que.front();
            pair<int,int> currCell=node.first;
            que.pop();
            int nodeX=currCell.first;
            int nodeY=currCell.second;
            int cost=node.second;
            // if(currCell==desti) return vis[nodeX][nodeY];
            if(currCell==desti) return cost;
            
            // bfsCheck()
            // top
            if(isSafe(nodeX-1,nodeY,N,M) && A[nodeX-1][nodeY]==1){
                // if(nodeX-1==X && nodeY==Y) return min(cost+1, vis[nodeX-1][nodeY]);
                que.push({{nodeX-1,nodeY},cost+1});
                // vis[nodeX-1][nodeY]=min(cost+1, vis[nodeX-1][nodeY]);
                A[nodeX-1][nodeY]==2;
            }
            
            
            // right
            if(isSafe(nodeX,nodeY+1,N,M) && A[nodeX][nodeY+1]==1){
                // if(nodeX==X && nodeY+1==Y) return min(cost+1, vis[nodeX][nodeY+1]);
                que.push({{nodeX,nodeY+1}, cost+1});
                // vis[nodeX][nodeY+1]=min(cost+1, vis[nodeX][nodeY+1]);
                A[nodeX][nodeY+1]==2;
            
            }
            
            
            // down
            if(isSafe(nodeX+1,nodeY,N,M) && A[nodeX+1][nodeY]==1){
                // if(nodeX+1==X && nodeY==Y) return min(cost+1, vis[nodeX+1][nodeY]);
                que.push({{nodeX+1,nodeY},cost+1});
                // vis[nodeX+1][nodeY]=min(cost+1, vis[nodeX+1][nodeY]);
                A[nodeX+1][nodeY]==2;
                
            }
            
            
            // left
            if(isSafe(nodeX,nodeY-1,N,M) && A[nodeX][nodeY-1]==1){
                // if(nodeX==X && nodeY-1==Y) return min(cost+1, vis[nodeX][nodeY-1]);
                que.push({{nodeX,nodeY-1}, cost+1});
                // vis[nodeX][nodeY-1]=min(cost+1, vis[nodeX][nodeY-1]);
                A[nodeX][nodeY-1]==2;
                
            }
        }
        
        // if(vis[X][Y]==INT_MAX) return -1;
        return -1;
    }
};



// Working Solution
class Solution {
  public:
    bool isSafe(int row, int col,vector<vector<int>> &A){
         int n=A.size();
         int m=A[0].size();
         if(row<0||col<0||row>n-1||col>m-1||A[row][col]==0)
         return 0;
         return 1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[0][0]==0 || A[X][Y]==0)
            return -1;
        
        vector<vector<int>> vis(N, vector<int> (M,0));
        queue<pair<pair<int,int>,int>> que;
        que.push({{0,0},0});
        vis[0][0]=1;
        
        while(!que.empty()){
            pair<pair<int,int>,int> node = que.front();
            que.pop();
            int nodeX=node.first.first;
            int nodeY=node.first.second;
            
            if(nodeX==X && nodeY==Y) return node.second;
            
            int cost=node.second;
            
            // bfsCheck
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            
            for(int i=0;i<4;i++)
            {
                if(isSafe(nodeX+dx[i],nodeY+dy[i],A)&&!vis[nodeX+dx[i]][nodeY+dy[i]])
                {
                    que.push({{nodeX+dx[i],nodeY+dy[i]},cost+1});
                    vis[nodeX+dx[i]][nodeY+dy[i]]=1;
                }
            }
        }
        
        return -1;
    }
};