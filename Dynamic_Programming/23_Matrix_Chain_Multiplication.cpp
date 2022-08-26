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
    int solveRec(int arr[], int lft, int rgt){
        
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
    // when start point of k => i, end point of k => j-1, 
    int solve1(int arr[], int lft, int rgt, vector<vector<int>>&dp){
        
        if(lft>=rgt) return 0;
        if(dp[lft][rgt]!=-1) return dp[lft][rgt];
        
        int ans=INT_MAX;
        for(int k=lft; k<=rgt-1; k++){
            int tmpAns = solve1(arr, lft, k, dp) + solve1(arr, k+1, rgt, dp) + (arr[lft-1]*arr[k]*arr[rgt]);
            ans = min(ans, tmpAns);
        }
        
        dp[lft][rgt] = ans;
        return ans;
    }
    
    
    // when start point of k => i+1, end point of k => j, 
    int solve2(int arr[], int lft, int rgt, vector<vector<int>>&dp){
        
        if(lft>=rgt) return 0;
        if(dp[lft][rgt]!=-1) return dp[lft][rgt];
        
        int ans=INT_MAX;
        for(int k=lft+1; k<=rgt; k++){
            int tmpAns = solve2(arr, lft, k-1, dp) + solve2(arr, k, rgt, dp) + (arr[lft-1]*arr[k-1]*arr[rgt]);
            ans = min(ans, tmpAns);
        }
        
        dp[lft][rgt] = ans;
        return ans;
    }
    
    
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N,-1));

        // return solveRec(arr, 1, N-1);
        // return solve1(arr, 1, N-1, dp);
        return solve2(arr, 1, N-1, dp);
        
    }
};



// Code Ends Here