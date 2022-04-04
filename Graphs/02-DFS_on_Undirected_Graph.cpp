/*
    Problem: DFS traversal on undirected Graph
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:
        Method-I
        Using Stack

        Method-II
        Using Recursion

    
*/

// Using Stack 
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        stack<int> stk;
        
        stk.push(0);
        
        while(!stk.empty()){
            int node=stk.top();
            stk.pop();
            
            if(vis[node])continue;
            
            ans.push_back(node);
            vis[node]=1;
            vector<int> tmp=adj[node];
            for(int i=tmp.size()-1; i>=0; i--){
                stk.push(tmp[i]);
            }
        }
        
        return ans;
    }
};