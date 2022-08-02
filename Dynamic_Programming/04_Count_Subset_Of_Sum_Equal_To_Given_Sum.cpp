// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(N*sum)
        Expected Auxiliary Space: O(N*sum)

    Algorithm:

    
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int mod=1000000007;
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int col=0; col<sum+1; col++)
            dp[0][col] = 0;
        for(int row=0; row<n+1; row++)
            dp[row][0] = 1;
            
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                // Here, this loop is starting from 0 not 1 as any other Knapsack variation codes,
                // it is bcoz the given constraints, i.e 0<=arr[i]<=10^6 which means array elements
                // can be equal to 0 as well, it means there are more than one way to generate the
                // subset whose sum is equal to 0, i.e {} (null subset) and {0} (the subset which
                // contains one element whose sum is zero).
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
                }
                else dp[i][j] = dp[i-1][j] % mod;
            }
        }
        
        
        return dp[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends




// Code Ends Here