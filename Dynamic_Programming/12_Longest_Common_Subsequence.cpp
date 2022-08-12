// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
        Leetcode: https://leetcode.com/problems/longest-common-subsequence/submissions/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity : O(|str1|*|str2|)
        Expected Auxiliary Space: O(|str1|*|str2|)
        

    Algorithm:

    
*/



// Leetcode Solution (GFG also same only function structure is change)
class Solution {
public:




    // ************************ Recursive Approach ************************
    int LCS(string s1, string s2, int n, int m, vector<vector<int>>&dp){
        //Base case
        if(n==0 || m==0) return 0;
        
        if(s1[n-1]==s2[m-1]){
            return LCS(s1, s2, n-1, m-1, dp) + 1;
        }
        else{
            return max(LCS(s1, s2, n, m-1, dp), LCS(s1, s2, n-1, m, dp));
        }
        
        return -1;
    }




    // ************************ Memoization/Top-Down ************************
    vector<vector<int>> dp(1001, vector<int>(1001, -1)); // its your choice to make it global or local

    int LCS(string s1, string s2, int n, int m, vector<vector<int>>&dp){
        //Base case
        if(n==0 || m==0) return 0;
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(s1[n-1]==s2[m-1]){
            dp[n][m]=LCS(s1, s2, n-1, m-1, dp) + 1;
            return dp[n][m];
        }
        else{
            dp[n][m]=max(LCS(s1, s2, n, m-1, dp), LCS(s1, s2, n-1, m, dp));
            return dp[n][m];
        }
        
        return -1;
    }




    // ************************ Tabulation/Bottom-Up ************************
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
    }




};



// Code Ends Here