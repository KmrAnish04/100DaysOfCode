/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
-105 <= a[i] <= 105

*/

/*---------------------------------------------------------------------------------------------------------------------------*/


// Soution: 1


/*
    Brute-Force Soution:
    Approch: Generate all the subarrays and find a particular subarray having sum zero.
    Time complexity: O(n^2)
    Space complexity: O(1)
*/

class SolutionBruteForce{
    public:
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i=0; i<n; i++){
            int sum=0;
            if(arr[i]==0){
                return true;
            }
            else{
                sum=arr[i];
                for(int j=i+1; j<n; j++){
                    sum += arr[j];
                    if(sum==0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



// Soution: 2


/*
    Optimal Soution:
    Approch: We are using maps in this solution and using the technique "Prefix Sum" and checking these three conditons only i.e if arr[i]==0, sum==0 and prefixSum[sum]>=1 is true then return true.
    Time complexity: O(N)
    Space complexity: O(1)
*/

class SolutionOptimalApproch{
    public:
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int sum=0;
        unordered_map<int, int>prefixSum;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(prefixSum[sum]>=1 || sum == 0 || arr[i]==0) return true;
            else{
                prefixSum[sum]++;
            }
        }
        
        return false;
    }
};