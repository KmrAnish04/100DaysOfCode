// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
        Leetcode: https://leetcode.com/problems/partition-equal-subset-sum/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(N*sum of elements)
        Expected Auxiliary Space: O(N*sum of elements)

    Algorithm:

    
*/



// Leetcode Solution
class Solution {
public:
    bool isSubsetSum(vector<int>arr, int Sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(Sum+1));
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=true;
        for(int i=1;i<Sum+1;i++)
            dp[0][i]=false;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<Sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][Sum];
    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum%2 == 0){
            return isSubsetSum(nums, totalSum/2);
        }
        
        
        return false;
    }
};



// GFG Solution
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int Sum){
        // code here 
        // int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(Sum+1));
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=true;
        for(int i=1;i<Sum+1;i++)
            dp[0][i]=false;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<Sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][Sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = accumulate(arr, arr+N, 0);
        
        if(totalSum%2 == 0){
            return isSubsetSum(arr, N, totalSum/2);
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends