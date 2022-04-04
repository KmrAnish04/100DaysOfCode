/*
    Problem: BFS traversal on directed Graph
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
        Leetcode:

    Complexity Analysis:
        Expected Time Complexity: O(V + E)
        Expected Auxiliary Space: O(V)

    Algorithm:
        Use a boolean list to mark all the vertices as not visited.

        Initially mark first vertex as visited(true).

        Create a queue for BFS and push first vertex in queue.

        While queue is not empty:

        Keep adding front element in output list and popping it from queue.
        Traverse over all the connected components of front element.
        If they aren't visited, mark them visited and add to queue.
        Return the output list.

    
*/


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V,0);
        queue<int> que;
        
        que.push(0);
        vis[0]=1;
        
        while(!que.empty()){
            int node=que.front();
            que.pop();
            ans.push_back(node);
            vector<int> tmp=adj[node];
            for(int j=0; j<tmp.size(); j++){
                if(vis[tmp[j]]==0){
                    que.push(tmp[j]);
                    vis[tmp[j]]=1;
                }
            }
        }
        
        return ans;
    }
};



