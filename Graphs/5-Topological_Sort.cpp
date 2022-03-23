/*
    Problem: Find Topological Sort of DAG
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/topological-sort/1#
        Leetcode:

    Complexity Analysis:
        Time: O(V+E)
        Space: O(V)

    Algorithm:
        GFG Algorithm:
            Topological sorting for Directed Acyclic Graph (DAG) is a linear 
            ordering of vertices such that for every directed edge u v, vertex u 
            comes before v in the ordering. So, to find the Topological sorting for a graph, 
            we just have to find in-degrees of each vertex and order the nodes from least in-degree 
            to the highest.

            Algorithm to find Topological Sorting: 
            We recommend to first see the implementation of DFS. We can modify DFS to find Topological Sorting of a graph. 
            In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. 
            In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively 
            call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack. 
            Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 

        
        
        
        Methods:
            1. Using DFS : Solution Reference Video Link: https://www.youtube.com/watch?v=Yh6EFazXipA&t=210s
            2. Using BFS

    
*/

// DFS Approch
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void findTopo(int node, vector<int> &vis, stack<int> &stk, vector<int> adj[]){
	    vis[node]=1;
	    
	    for(auto it: adj[node]){
	        if(vis[it]==0)
	            findTopo(it, vis, stk, adj);
	    }
	    
	    stk.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> vis(V,0);
	    stack<int> stk;
	    
	    for(int i=0; i<V; i++){
	        if(vis[i]==0)
	            findTopo(i, vis, stk, adj);
	    }
	    
	    while(!stk.empty()){
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    
	    return ans;
	}
};

