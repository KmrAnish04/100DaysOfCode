// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>> dp;
    int solve(int n, int f){
        
        if(f==0 || f==1) return f;
        if(n==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = 1 + max(solve(n-1, k-1), solve(n, f-k));
            
            ans = min(ans, temp);
        }
        
        return dp[n][f] = ans;
    }
    
    int eggDrop(int n, int f) 
    {
        // your code here
        dp.resize(n+1,vector<int>(f+1,-1));
        return solve(n,f);
        
    }
};





// Code Ends Here