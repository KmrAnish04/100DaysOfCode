/*
    Problem: Detect Cycle In Directed Graph
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
        Leetcode:

    Complexity Analysis:
        Time: O(V+E)
        Space: O(V)

    Algorithm:
        Method-1
        Using DFS (Recusive Approch)

        Method-2
        Using Kahn's Algorithm (Topological Sort Concept)

    
*/

// Recursive Solution
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node, vector<int> &vis, vector<int> &dvis, vector<int> adj[]){
        vis[node]=1;
        dvis[node]=1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfsCheck(it, vis, dvis, adj)) return true;
            }
            else if(dvis[it]==1) return true;
        }
        
        dvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dvis(V,0);
        
        for(int i=0; i<V; i++){
            if(vis[i]==0 && dfsCheck(i, vis, dvis, adj)) return true;
        }
        
        return false;
    }
};

