// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
        Leetcode: 
        pepcoding: 
        nados: 

        

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/


// GFG Solution : Minimum No. of Deletions
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

int minDeletions(string A, int n) { 
    //complete the function here 
    string B = A;
    reverse(B.begin(), B.end());
    
    int LPS = LCS(A, B, n, n);
    
    return n-LPS;
} 


// Code Ends Here