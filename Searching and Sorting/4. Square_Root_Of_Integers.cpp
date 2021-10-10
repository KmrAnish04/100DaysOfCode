// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*
    Time Complexity: O(sqrt N)
    Space Complexity: O(1)
*/
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int cnt=0;
        
        for(int i=1; i<=sqrt(N); i++){
            int sqr = i*i;
            if(sqr<N) cnt++;
            else break;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends