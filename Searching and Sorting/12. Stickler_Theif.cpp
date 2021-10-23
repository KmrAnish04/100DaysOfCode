class Solution
{
    public:
    //Function to find the maximum money the thief can get.

    // Optimized Solution
    //     Time Complexity: O(N)
    //     Space Complexity: O(1)
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int incl = arr[0];
        int excl = 0;
        
        for(int i=1; i<n; i++){
            int tmpIncl = excl+arr[i];
            excl = max(incl, excl);
            incl = tmpIncl;
        }
        
        return max(incl, excl);
    }
};