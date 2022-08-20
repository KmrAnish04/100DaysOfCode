// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: https://leetcode.com/problems/shortest-common-supersequence/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/



class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int i=n, j=m;
        string ans="";
        
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--; j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    ans+=s2[j-1];
                    j--;
                }
                else{
                    ans+=s1[i-1];
                    i--;
                }
            }
        }
        
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};



// Code Ends Here