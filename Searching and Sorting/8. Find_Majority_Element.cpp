/*
    Moore's Voting Algorithm
    Time Complexity: O(N)
    Space Complexity: O(1)

*/

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int cnt1=1;
        int cnt2=0;
        int res=0;
        
        for(int i=1; i<size; i++){
            if(a[res]==a[i]) cnt1++;
            else cnt1--;
            
            if(cnt1==0){
                cnt1=1;
                res=i;
            }
        }
        
        for(int i=0; i<size; i++){
            if(a[res]==a[i]) cnt2++;
        }
        
        if(cnt2 > (size/2)) return a[res];
        
        return -1;
    }
};
