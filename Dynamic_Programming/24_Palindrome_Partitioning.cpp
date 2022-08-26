// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
        Leetcode: https://leetcode.com/problems/palindrome-partitioning-ii/submissions/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/

// GFG solution
class Solution{
public:
    /*
        To avoid TLE,  just pass the string as a reference 
        to the functions to avoid creating copies and declare 
        the dp table in a global scope to reduce the memory 
        used in stack space for each recursive call.



        Further Optimization can be done by replacing the for loop of k with:
            for(int k=i;k<j;k++)
            {
                if(isPalindrome(s, i, k))
                {                         
                    int temp = solve (s, k+1, j) + 1;
                    ans = min (ans, temp);
                }
            }
            return dp[i][j]=ans;
    
    */

    // vector<vector<int>> dp(501, vector<int>(501, -1));
    int dp[501][501];
    bool isPalin(string &s, int i, int j)
    {
        int m,n;
        for(int m=i,n=j;m<=(i+j)/2;m++,n--)
        {
            if(s[m]!=s[n])
                return false;
        }
        return true;
    }
    
    
    int solveRec(string &str, int low, int high){
        
        if(low>=high || isPalin(str, low, high)) return 0;

        if(dp[low][high]!=-1) return dp[low][high];
        
        int ans = INT_MAX;
        for(int k=low; k<high; k++){
            int tmpAns = solveRec(str, low, k) + solveRec(str, k+1, high) + 1;
            ans = min(ans, tmpAns);
        }
        
        dp[low][high] = ans;
        return ans;
    }


    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        memset(dp,-1,sizeof(dp));
        return solveRec(str, 0, n-1);
    }
};




// Leetcode solution
class Solution {
public:
    int dp[2010][2010];
    bool isPalin(string &s, int i, int j)
    {
        int m,n;
        for(int m=i,n=j;m<=(i+j)/2;m++,n--)
        {
            if(s[m]!=s[n])
                return false;
        }
        return true;
    }
    
    
    int solveRec(string &str, int low, int high){
        
        if(low>=high || isPalin(str, low, high)) return 0;

        if(dp[low][high]!=-1) return dp[low][high];
        
        int ans = INT_MAX;
        for(int k=low; k<high; k++){
            
            if(isPalin(str, low, k))
            {                         
                int temp = solveRec (str, k+1, high) + 1;
                ans = min (ans, temp);
            }
            // int tmpAns = solveRec(str, low, k) + solveRec(str, k+1, high) + 1;
            // ans = min(ans, tmpAns);
        }
        
        dp[low][high] = ans;
        return ans;
    }
    int minCut(string str) {
        int n=str.length();
        memset(dp,-1,sizeof(dp));
        return solveRec(str, 0, n-1);
    }
};



// Code Ends Here