// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/

// Recursive Solution
// Time Complexity: O(n * (2^min(n,k))
// Space Complexity: O(1) , If we ignore space taken by stack frame
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n, int f){
        
        if(f==0 || f==1) return f;
        if(n==1) return f;
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = 1 + max(solve(n-1, k-1), solve(n, f-k));
            
            ans = min(ans, temp);
        }
        
        return ans;
    }
    
    int eggDrop(int n, int f) 
    {
        // your code here
        return solve(n,f);

    }
};




// GFG Solution
// works only on GFG portal

// Time Complexity: O((n^2) * k)
// Space Complexity: O(k * n)
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>> dp;
    int solve(int n, int f){
        
        if(f==0 || f==1) return f;
        if(n==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = 1 + max(solve(n-1, k-1), solve(n, f-k));
            
            ans = min(ans, temp);
        }
        
        return dp[n][f] = ans;
    }
    
    int eggDrop(int n, int f) 
    {
        // your code here
        dp.resize(n+1,vector<int>(f+1,-1));
        return solve(n,f);
        
    }
};




// Optimization - 2
// GFG solution (worte on Leetcode but doesn't worked giving TLE but will surely work on GFG)
// This code solution works on GFG Portal, Leetcode needs some more optimization

// Time Complexity: O((n^2) * k)
// Space Complexity: O(k * n)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int f){
        
        if(f==0 || f==1) return f;
        if(n==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int eggBrokeCall; 
            int eggSurvivedCall;
            
            if(dp[n-1][k-1]!=-1) eggBrokeCall=dp[n-1][k-1];
            else{
                eggBrokeCall = solve(n-1, k-1);
                dp[n-1][k-1]=eggBrokeCall;
            }
            
            if(dp[n][f-k]!=-1) eggSurvivedCall = dp[n][f-k];
            else{
                eggSurvivedCall = solve(n, f-k);
                dp[n][f-k] = eggSurvivedCall;
            }
            
            
            int temp = 1 + max(eggBrokeCall, eggSurvivedCall);
            
            ans = min(ans, temp);
        }
        
        return dp[n][f] = ans;
    }
    int superEggDrop(int n, int f) {
        dp.resize(n+1,vector<int>(f+1,-1));
        return solve(n,f);
    }
};




// Optimization - 3
// Leetcode Solution
// Works on both Leetcode and GFG (Optimized using Binary Search)

// Time Complexity: O((n * k) * logn )
// Space Complexity: O(n * k)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int f){
        
        if(f==0 || f==1) return f;
        if(n==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int ans = INT_MAX;
        
        int low=1, high=f;
        while(low<=high){
            // solve(n-1,mid-1)
            // solve(n, f-mid)
        
            int mid = (low + high)/2;
        
            
            
            int eggBrokeCall; 
            int eggSurvivedCall;
            
            if(dp[n-1][mid-1]!=-1) eggBrokeCall=dp[n-1][mid-1];
            else{
                eggBrokeCall = solve(n-1, mid-1);
                dp[n-1][mid-1]=eggBrokeCall;
            }
            
            if(dp[n][f-mid]!=-1) eggSurvivedCall = dp[n][f-mid];
            else{
                eggSurvivedCall = solve(n, f-mid);
                dp[n][f-mid] = eggSurvivedCall;
            }
            
            /*
                Basic Binary Serach Code.
                Why Binary Serach works here, bcoz we have to find minimum attempts in worst case, therefore
                whichever recursive call (left or right) gives maximum attempts, we'll consider that call to
                maintain the worst case consistency.
                
                if(leftCall > rightCall){
                    high = mid+1;
                }
                else{
                    low = mid+1
                }
            */
            
            if(eggBrokeCall>eggSurvivedCall){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
            
            int temp = 1 + max(eggBrokeCall, eggSurvivedCall);
            
            ans = min(ans, temp);
        }
        
        return dp[n][f] = ans;
    }
    int superEggDrop(int n, int f) {
        dp.resize(n+1,vector<int>(f+1,-1));
        return solve(n,f);
    }
};



// To see Tabulation/Bottom-Up Approach also, follow this Discuss Section on LeetCode:
// Link: https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand

// Code Ends Here