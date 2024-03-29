// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

 // Solution Starts Here
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        // using kadane's method
        int resultantArray[n];
        int maximumSum = resultantArray[0] = arr[0];
        
        for(int i=1; i<n; i++){
            resultantArray[i] = max(arr[i], resultantArray[i-1]+arr[i]);
            
            if(resultantArray[i] > maximumSum){
                maximumSum = resultantArray[i];
            }
        }
        
        return maximumSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends