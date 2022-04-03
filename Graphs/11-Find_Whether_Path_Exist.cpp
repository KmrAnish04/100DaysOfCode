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


// Solution by GFG
class Solution 
{
    public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};  
    
    //Function to check whether the cell is within the matrix bounds.
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 and x < n and y >=0 and y < m);
    }
    
    //Function to find whether a path exists from the source to destination. 
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        //creating BFS queue 
        queue<pair<int, int>>q;
        
        //traversing all the cells of the matrix.
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        	    //if there exists a cell in the matrix such that its 
                //value is 1 then we push it to queue.
        		if(grid[i][j] == 1){
        			q.push({i,j});
        		}
        	}
        }
        
        while(!q.empty())
        {
        	int x = q.front().first;
        	int y = q.front().second;
        	q.pop();
        	for(int i = 0; i < 4; i++)
        	{
        		int n_x = x + dx[i];
        		int n_y = y + dy[i];
        		
        		//if the cell is within matrix bounds.
        		if(isValid(n_x, n_y, n, m))
        		{
        		    //if the value of current cell is 2, we return true.
        			if(grid[n_x][n_y] == 2)
        				return true;
        				
        			//if the value of current cell is 3, we replace the value
        			//with 1 and push the cell into the queue.
        			if(grid[n_x][n_y] == 3){
        				grid[n_x][n_y] = 1;
        				q.push({n_x, n_y});
        			}
        		}
        	}
        }
        return false;

    }
};


// Solution Using the same concept of previous question (Shortest source to destination path)
class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isSafe(int row, int col,vector<vector<int>> &A){
         int n=A.size();
         int m=A[0].size();
         if(row<0||col<0||row>n-1||col>m-1||A[row][col]==0)
         return 0;
         return 1;
    }
    bool is_Possible(vector<vector<int>>& A) 
    {
        //code here
        pair<int,int> src;
        int X;
        int Y;
        int N=A.size();
        int M=A[0].size();
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j]==1){
                    src.first=i;
                    src.second=j;
                }
                else if(A[i][j]==2){
                    X=i;
                    Y=j;
                }
            }
        }
        
        
        // if(A[0][0]==0 || A[X][Y]==0)
        //     return -1;
        
        vector<vector<int>> vis(N, vector<int> (M,0));
        queue<pair<pair<int,int>,int>> que;
        que.push({{src.first,src.second},0});
        vis[0][0]=1;
        
        while(!que.empty()){
            pair<pair<int,int>,int> node = que.front();
            que.pop();
            int nodeX=node.first.first;
            int nodeY=node.first.second;
            
            if(nodeX==X && nodeY==Y) return node.second;
            if(nodeX==X && nodeY==Y) return 1;
            
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
        
        return 0;
    }
};


