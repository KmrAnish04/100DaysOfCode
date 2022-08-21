// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: https://leetcode.com/problems/is-subsequence/submissions/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:
    This question can be solved by various metchod, 
    for eg: 1. Two Pointer Approach [ T.C : O(N) ]
            2. DP Approach--LCS Variation [ T.C : O(N * M)]
            3. Other Concept

    As this is DP Series, we focused on DP Approach but i implemented only for learning DP but DP is not worth for this questionl, for this question Two pointer
    approcah is best as time complexity is liner but for DP its very high i.e O(N*M).

    
*/

class Solution {
public:
    // Two Pointer Approach
    bool twoPointerApproach(string s, string t){
        if(s.length()>t.length()) return false;
        
        int p1=0, p2=0;
        while(p1<s.length() && p2<t.length()){
            if(s[p1]==t[p2]){
                p1++; p2++;
            }
            else{
                p2++;
            }
        }
        
        if(p1<s.length()) return false;
        
        return true;

    }

    // LCS Approach
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

    
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        int lcsLen = LCS(s, t, n, m);
        if(lcsLen!=s.length()) return false;
        return true;
        
        // return twoPointerApproach(s, t);
        
    }
};





// Code Ends Here