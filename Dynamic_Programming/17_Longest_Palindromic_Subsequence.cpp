// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
        Leetcode: https://leetcode.com/problems/longest-palindromic-subsequence/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/


class Solution{
  public:
  int LCS(string X, string Y, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.length();
        string B = A;
        reverse(B.begin(), B.end());
        
        return LCS(A, B, n, n);
    }
};




// Code Ends Here