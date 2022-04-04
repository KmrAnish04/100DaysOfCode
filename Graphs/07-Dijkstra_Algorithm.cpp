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

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
        vector<int> dist(V+1,INT_MAX);
        dist[S]=0;
        que.push({0,S});
        
        while(!que.empty()){
            pair<int,int> node=que.top();
            int cost=node.first;
            int desti=node.second;
            que.pop();
            
            for(auto it:adj[desti]){
                if(it[1]+cost<dist[it[0]]){
                    que.push({it[1]+cost,it[0]});
                    dist[it[0]]=it[1]+cost;
                }
            }
        }
        
        return dist;
        
    }
};