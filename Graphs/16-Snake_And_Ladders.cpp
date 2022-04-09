/*
    Problem: Snakes and Ladders
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1#
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        int moves=0;
        vector<int> vis(30, 0);
        vector<int> brd(30, -1);
        
        for(int i=0; i<2*N; i=i+2)
            brd[arr[i]]=arr[i+1];
        
        
        queue<int> stk;
        stk.push(1);
        vis[1]=1;
        
        while(!stk.empty()){
            int currStkSize = stk.size();
            moves++;
            for(int i=0; i<currStkSize; i++){
                int node=stk.front();
                stk.pop();
                for(int j=1; j<=6; j++){
                    int nxtNode=node+j;
                    if(nxtNode==30) return moves;
                    else if(nxtNode>30) continue;
                    else if(nxtNode<30 and !vis[nxtNode] and brd[nxtNode]!=-1){
                        if(brd[nxtNode]==30){
                            return moves;
                        }
                        vis[nxtNode]=1;
                        stk.push(brd[nxtNode]);
                    }
                    else {
                        vis[nxtNode]=1;
                        stk.push(nxtNode);
                    }
                }
            }
        }
        
        return -1;
    }
};

