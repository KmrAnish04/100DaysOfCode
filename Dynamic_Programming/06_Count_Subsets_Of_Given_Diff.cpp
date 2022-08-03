// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: 
        pepcoding: 
        nados: 

        actual qestion link didn't found, but this question is exactly
        same as Leetcode question that is Target Sum, which is next 
        question in this DP list.

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/


/*
    Problem Statement:
    Given an array of integers 'nums' and an interger 'diff'.
    find the total no. of subset whose sums difference is equal to given
    no. 'diff'.
    For eg: arr[] = {1,2,7}, diff = 3
    Answer: 1
    
    so valid subset will be, {1,2}, {7}, bcos (1+2) - (7) = |-3| = 3 = diff

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
    int countNoOfSubsetsOfGivenDiff(vector<int>& nums, int diff) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if((totalSum-diff)%2==1 || totalSum<diff) return 0;
        
        int s1 = (totalSum-diff)/2;
        
        // And for (sum - diff) % 2 == 1) since diff can be negative so its clever way to avoid negative array size exception since we have already checked that sum should always be gretaer than diff therefore we will always get a positive value for our memo array.
            
        
        
        return countOfSubsetSum(nums, s1);
    }
};




// Code Ends Here