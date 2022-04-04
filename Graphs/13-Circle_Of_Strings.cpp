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
    void dfs(vector<int> adj[], vector<int> &vis, int src){
        vis[src]=1;
        for(auto it: adj[src]){
            if(vis[it]!=1){
                dfs(adj, vis, it);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> adj[26];
        vector<int> in(26,0);
        vector<int> out(26,0);
        
        for(int i=0 ; i<N ; i++)
        {
            int a = A[i][0] - 'a';
            int b = A[i].back() - 'a';
            in[a]++;
            out[b]++;
            adj[a].push_back(b);
        }
        
        
        // checking whether all the nodes has same degree or not
        for(int i=0; i<26; i++)
            if(in[i]!=out[i]) return 0;
            
        
        //checking whether all the components of graph are connected or not
        int src;
        for(int i=0; i<26; i++){
            if(in[i]!=0){
                src=i;
                break;
            }
        }
        vector<int> vis(26,0);
        dfs(adj, vis, src);
        for(int i=0; i<26; i++){
            if(vis[i]==0 && in[i]) return 0;
        }
        
        
        
        return 1;
    }
};

