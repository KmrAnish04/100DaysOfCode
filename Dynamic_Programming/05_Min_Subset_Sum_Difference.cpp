// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<int> subsetSum(int arr[], int n, int Sum){
        vector<vector<bool>> dp(n+1, vector<bool>(Sum+1));
        
        for(int col=0; col<Sum+1; col++)
            dp[0][col] = false;
        for(int row=0; row<n+1; row++)
            dp[row][0] = true;
            
            
        for(int i=1; i<n+1; i++){
            for(int j=1; j<Sum+1; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        vector<int> vec;
        for(int col=0; col<=(Sum)/2; col++){
            if(dp[n][col]){
                vec.push_back(col);
            }
        }
        
        return vec;
            
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int minDiff = INT_MAX;
	    int totalSum = accumulate(arr, arr+n, 0);
	    
	    vector<int> validSS = subsetSum(arr, n, totalSum); // valid subset Sums == validSS
	    
	    for(int i=0; i<validSS.size(); i++){
            minDiff = min( minDiff, totalSum-(2*validSS[i]) );
	    }
	    
	    return minDiff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends





// Code Ends Here