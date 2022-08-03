// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: https://leetcode.com/problems/target-sum/submissions/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/



class Solution {
public:
    int countOfSubsetSum(vector<int> nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int col=0; col<sum+1; col++){
            dp[0][col]=0;
        }
        for(int row=0; row<n+1; row++){
            dp[row][0]=1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if((totalSum-target)%2==1 || totalSum<target) return 0;
        
        int s1 = (totalSum-target)/2;
        
        // And for (sum - target) % 2 == 1) since target can be negative so its clever way to avoid negative array size exception since we have already checked that sum should always be gretaer than target therefore we will always get a positive value for our memo array.
            
        
        
        return countOfSubsetSum(nums, s1);
    }
};



// Code Ends Here