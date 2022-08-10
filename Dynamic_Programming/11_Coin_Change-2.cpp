// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
        Leetcode: https://leetcode.com/problems/coin-change/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(V*M)
        Expected Auxiliary Space: O(V)

    Algorithm:

    
*/


// GFG Solution
class Solution{

	public:
	int minCoins(int coins[], int N, int amt) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(N+1, vector<int>(amt+1));
	    for(int i=0; i<amt+1; i++){
	        dp[0][i]=INT_MAX-1;
	    }
	    for(int i=1; i<N+1; i++){
	        dp[i][0]=0;
	    }
	    for(int i=1; i<amt+1; i++){
	        if(i%coins[0]==0){
    	        dp[1][i]=i/coins[0];
	        }
	        else{
	            dp[1][i]=INT_MAX-1;
	        }
	    }
	    
	    
	    for(int i=2; i<N+1; i++){
	        for(int j=1; j<amt+1; j++){
	            if(coins[i-1]<=j){
	                dp[i][j]=min(dp[i][j-coins[i-1]] + 1 , dp[i-1][j]);
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    if(dp[N][amt]==INT_MAX-1) return -1;
	    
	    return dp[N][amt];
	} 
	  
};





// Leetcode Solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int N=coins.size();
        vector<vector<int>> dp(N+1, vector<int>(amt+1));
        
        // Initialization of 1st row and 1st column
	    for(int i=0; i<amt+1; i++) dp[0][i]=INT_MAX-1;
	    for(int i=1; i<N+1; i++) dp[i][0]=0;
        
        // Initialization of 2nd row
	    for(int i=1; i<amt+1; i++){
	        if(i%coins[0]==0)dp[1][i]=i/coins[0];    
	        else dp[1][i]=INT_MAX-1;
	    }
	    
	    
        // Main Logic: Variation of Unbounded Knapsack
	    for(int i=2; i<N+1; i++){
            for(int j=1; j<amt+1; j++){
                if(coins[i-1]<=j) dp[i][j]=min(dp[i][j-coins[i-1]] + 1 , dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
	        }
	    }
	    
        // If coin combination is not possible to get required amount
	    if(dp[N][amt]==INT_MAX-1) return -1;
	    
	    return dp[N][amt];
    }
};



// Code Ends Here