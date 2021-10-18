// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    /*
        The followin is the Otimized Approach.
        Time Complexity: O(N)
        Space Complexity: O(1)

        **There are also Brute-Force and sorting approach having Time and space Complexity O(N^2), O(N) and O(N Log N), O(1).**

    */
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans = new int[2];
        int missing;
        int repeating;
        
        for(int i=0; i<n; i++){
            if((arr[abs(arr[i])-1])>0){
                arr[abs(arr[i])-1] *= -1;
            }
            else{
                repeating = abs(arr[i]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                missing = i+1;
                break;
            }
        }
        
        ans[0]=repeating;
        ans[1]=missing;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends