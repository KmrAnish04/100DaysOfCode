
/*

Soution:1 Brute-Force Approch
TC = O(N^2)
SC = O(1)
Approch: Generate all minimum length subarrays where we are getting
sum greater than given value and then return the lenght of that subarray.

*/



/*

Soution:2
TC = O(N)
SC = O(1)
Approch: Using two pointer approch.

*/
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        
        // TC = O(N)
        // SC = O(1)

        int Len = INT_MAX;
        int sum = 0;
        int i = 0;
        int j = 0;
        
        while(i<=j and j<n){
            while(sum<=x and j<n){
              sum+=arr[j++];  
            } 
            
            while(sum>x and i<j){
                cLen = min(cLen, j-i);
                sum-=arr[i];
                i++;
            }
        }
        
        return Len;
    }
};