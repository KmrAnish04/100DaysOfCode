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

class Solution{
    public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &resStk){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                dfs(it, vis, adj, resStk);
            }
        }
        
        resStk.push(node);
    }
    
    string topoSort(vector<int> adj[], int V){
        
        string result;
        stack<int> resStk;
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                dfs(i, vis, adj, resStk);
            }
        }
        
        while(!resStk.empty()){
            result += resStk.top()+'a';
            resStk.pop();
        }
        
        return result;
    }
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=0; i<N-1; i++){
            string str1=dict[i];
            string str2=dict[i+1];
            for(int j=0; j<min(str1.length(), str2.length()); j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }
            }
        }
        
        return topoSort(adj, K);
    }
};

