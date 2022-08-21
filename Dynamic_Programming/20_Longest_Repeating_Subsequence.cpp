// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/

class Solution {
	public:
	   // This is same LCS Approach with very minor change/addition in 'if' condition
		int LongestRepeatingSubsequence(string s1){
		    // Code here
		    int n=s1.length();
		    string s2=s1;
		    vector<vector<int>> dp(n+1, vector<int>(n+1));
		    
		    for(int i=0; i<n+1; i++){
		        dp[i][0]=0;
		        dp[0][i]=0;
		    }
		    
		    for(int i=1; i<n+1; i++){
		        for(int j=1; j<n+1; j++){
		            if(s1[i-1]==s2[j-1] && i!=j){ //minor addition = 'i!=j'
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
		                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		            }
		        }
		    }
		    
		    
		    return dp[n][n];
		}

};





// Code Ends Here