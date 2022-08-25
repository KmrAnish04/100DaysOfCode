// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/
// Recursive Approach
class Solution{
public:
    int solve(int arr[], int lft, int rgt){
        
        if(lft>=rgt) return 0;
        
        int ans=INT_MAX;
        for(int k=lft; k<rgt; k++){
            int tmpAns = solve(arr, lft, k) + solve(arr, k+1, rgt) + (arr[lft-1]*arr[k]*arr[rgt]);
            ans = min(ans, tmpAns);
        }
        
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr, 1, N-1);
        
    }
};


// Memoization
class Solution{
public:
    int solve(int arr[], int lft, int rgt, vector<vector<int>>&dp){
        
        if(lft>=rgt) return 0;
        if(dp[lft][rgt]!=-1) return dp[lft][rgt];
        
        int ans=INT_MAX;
        for(int k=lft; k<rgt; k++){
            int tmpAns = solve(arr, lft, k, dp) + solve(arr, k+1, rgt, dp) + (arr[lft-1]*arr[k]*arr[rgt]);
            ans = min(ans, tmpAns);
        }
        
        dp[lft][rgt] = ans;
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return solve(arr, 1, N-1, dp);
        
    }
};



// Code Ends Here