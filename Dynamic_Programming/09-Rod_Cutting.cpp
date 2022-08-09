// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(N^2)
        Expected Auxiliary Space: O(N)

    Algorithm:

    
*/



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // below is the recursive solution for this problem,,,
    void recursive(int price[], int n, int sizeOfRod, int idx, int psf, int&maxProfit){
        if(sizeOfRod==0){
            maxProfit=max(psf, maxProfit);
            return;
        }
        if(sizeOfRod<0) return;
        
        for(int i=0; i<n; i++){
            sizeOfRod-=i+1;
            psf+=price[i];
            recursive(price, n, sizeOfRod, idx+1, psf, maxProfit);
            sizeOfRod+=i+1;
            psf-=price[i];
        }
    }
    
    // below is the DP solution to this problem,,,
    int cutRod(int price[], int n) {
        //code here
        // int maxPro=INT_MIN;
        // recursive(price, n, n, 0, 0, maxPro);
        // return maxPro;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        vector<int> len(n);
        
        for(int i=0; i<n; i++){
            len[i]=i+1;
        }
        for(int i=0; i<n+1; i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(len[i-1]<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends






// Code Ends Here