// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
        Leetcode:
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(sum*N)
        Expected Auxiliary Space: O(sum*N)

    Algorithm:
        Dynamic Programming Approach
    
*/




//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // Recursive code (was just practicing)
    // bool solve(vector<int>arr, int sum, int ssf, int idx, string str){
        
    //     if(ssf==sum){
    //         // cout<<"ssf:T "<<ssf<<endl; 
    //         return true;
    //     }
        
    //     if(idx==arr.size() || ssf>sum){
    //         return false;
    //     }
        
        
    //     // cout<<"curr ele: "<<idx<<endl;
    //     // cout<<str<<"--ssf: "<<ssf<<endl;
        
    //     bool yesCall = solve(arr, sum, ssf+arr[idx], idx+1, "yes call");
    //     bool noCall = solve(arr, sum, ssf, idx+1, "no call");
        
        
    //     return  yesCall || noCall; 
    // }

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
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends


