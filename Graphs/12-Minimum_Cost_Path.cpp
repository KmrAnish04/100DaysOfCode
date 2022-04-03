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


// Dijkstra Algortihm
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isSafe(int row, int col,vector<vector<int>> &A){
         int n=A.size();
         int m=A[0].size();
         if(row<0||col<0||row>n-1||col>m-1)
         return 0;
         return 1;
    }
    int minimumCostPath(vector<vector<int>>& A) 
    {
        // Code here
        int N=A.size();
        int M=A[0].size();
        int minCost=0;
        vector<vector<int>> vis(N, vector<int> (M,INT_MAX));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> que;
        que.push({A[0][0],{0,0}});
        vis[0][0]=A[0][0];
        
        while(!que.empty()){
            pair<int,pair<int,int>> node = que.top();
            que.pop();
            int nodeX=node.second.first;
            int nodeY=node.second.second;
            minCost+=node.first;
            if(nodeX==N-1 && nodeY==M-1) break;
            
            // int cost=node.second;
            
            // bfsCheck
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            
            for(int i=0;i<4;i++)
            {   
                int newRow=nodeX+dx[i]; 
                int newCol=nodeY+dy[i];
                if(isSafe(newRow,newCol,A))
                {
                    if(vis[newRow][newCol]>=vis[nodeX][nodeY]+A[newRow][newCol]){
                       vis[newRow][newCol] = vis[nodeX][nodeY] + A[newRow][newCol];
                       que.push({vis[newRow][newCol],{newRow, newCol}});
                   }
                    // vis[newRow][newCol]=min(vis[newRow][newCol], A[newRow][newCol]+vis[nodeX][nodeY]);
                    // que.push({min(vis[newRow][newCol], A[newRow][newCol]+vis[nodeX][nodeY]), {newRow,newCol}});
                }
            }
        }
        
        return vis[N-1][M-1];
    }
};

