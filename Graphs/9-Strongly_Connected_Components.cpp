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


// Kosaraju's Algorithm
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void findTopo(int node, vector<int> &vis, stack<int> &stk, vector<int> adj[]){
	    vis[node]=1;
	    
	    for(auto it: adj[node]){
	        if(vis[it]==0)
	            findTopo(it, vis, stk, adj);
	    }
	    
	    stk.push(node);
	}
	
	void topoDFS(int node, vector<int> &vis, vector<int> adjT[]){
	    vis[node]=1;
	    for(auto it: adjT[node]){
	        if(vis[it]==0)
	            topoDFS(it,vis, adjT);
	    }
	}
	
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        // Topological Sorting of the given graph
        vector<int> topoSort;
        vector<int> topoVis(V,0);
	    stack<int> stk;
	    for(int i=0; i<V; i++){
	        if(topoVis[i]==0)
	            findTopo(i, topoVis, stk, adj);
	    }
	    
	    while(!stk.empty()){
	        topoSort.push_back(stk.top());
	        stk.pop();
	    }
        
        // Making a transpose graph of the given graph
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        
        // DFS according to the topological sorting
        int count=0;
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(vis[topoSort[i]]==0){
                topoDFS(topoSort[i], vis, adjT);
                count++;
            }
        }
        
        return count;
    }
};