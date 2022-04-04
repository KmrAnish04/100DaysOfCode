/*
    Problem: Detect Cycle In an Undirected Graph
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:
        Method-1
        ***Using BFS***
            For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already 
            visited and u is not parent of v, then there is a cycle in graph. If we don’t find 
            such an adjacent for any vertex, we say that there is no cycle.
            (In simple words, MAIN LOGIC : - If a node is visited and is not equal to the parent, return True (i.e. cycle exists).)

        Method-2
        Using DFS

    
*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfsCheck(int m, vector<int> &vis, vector<int> adj[]){
        queue<pair<int,int>> que;
        que.push({m,-1});
        vis[m]=1;
        
        while(!que.empty()){
            pair<int,int> node=que.front();
            que.pop();
            
            vector<int> tmp=adj[node.first];
            for(int i=0; i<tmp.size(); i++){
                if(vis[tmp[i]]==0){
                    que.push({tmp[i],node.first});
                    vis[tmp[i]]=1;
                }
                else if(node.second!=tmp[i]){
                    return true;
                }
            }
        }
        
        return false;
    }


    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V; i++) // for multi-components 
            if(vis[i]==0 && bfsCheck(i, vis, adj)) return true;
        
        return false;
    }
};