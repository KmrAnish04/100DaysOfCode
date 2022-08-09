// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/coin-change2448/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(m*n).
        Expected Auxiliary Space: O(n).

    Algorithm:

    
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        // code here.
        // int n=coins.size();
        vector<vector<long long int>> dp(n+1, vector<long long int>(amount+1));
        
        for(int i=0; i<n+1; i++) dp[i][0]=1;
        
        for(int i=1; i<amount+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; 
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}
// } Driver Code Ends




// Code Ends Here