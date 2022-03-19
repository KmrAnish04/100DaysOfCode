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

// Using Stack (Not working now)
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        stack<int> stk;
        
        stk.push(0);
        vis[0]=1;
        
        while(!stk.empty()){
            int node=stk.top();
            // cout<<"curr Top: "<<node<<endl;
            stk.pop();
            ans.push_back(node);
            
            vector<int> tmp=adj[node];
            for(int i=0; i<tmp.size(); i++){
                if(vis[tmp[i]]==0){
                    stk.push(tmp[i]);
                    vis[tmp[i]]=1;
                }
            }
        }
        
        return ans;
    }
};

