// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(n*m)
        Expected Space Complexity: O(n*m)

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
    
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length();
	    int m=str2.length();

	    int lcs = LCS(str1, str2, n, m);
	    return (n-lcs)+(m-lcs);
	} 
};




// Code Ends Here