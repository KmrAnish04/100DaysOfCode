// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
        Leetcode: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
        pepcoding: 
        nados: 

        Actually, Here GFG question and Leetcode question is different in problem statement, (i.e  GFG: Minimum No. of Deletions and Leetcode: Minimum No. of Insertions)
        but their idea/concept/logic is almost same and even code is exactly same (not even minor changes). Therefore i am putting both the questions in same category.

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



// Leetcode Solution: Minimum No. of Insertions
class Solution {
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
    int minInsertions(string s1) {
        int n=s1.length();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        int LPS = LCS(s1, s2, n, n);
        
        return n-LPS;
    }
};


// Code Ends Here