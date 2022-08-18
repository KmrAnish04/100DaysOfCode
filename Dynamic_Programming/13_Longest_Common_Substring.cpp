// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(n*m).
        Expected Auxiliary Space: O(n*m).
        

    Algorithm:

    
*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int len=INT_MIN;
        
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=0;
                }
                len=max(len, dp[i][j]);
            }
        }
        
        return len;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}


// } Driver Code Ends



// Code Ends Here