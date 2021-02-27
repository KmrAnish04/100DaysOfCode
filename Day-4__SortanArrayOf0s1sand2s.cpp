// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int counterFor0 = 0;
        int counterFor1 = 0;
        int counterFor2 = 0;
        
        for(int i=0; i<n; i++){
            
            if(a[i] == 0){
                counterFor0++;
            }
            
            else if(a[i] == 1){
                counterFor1++;
            }
            
            else if(a[i] == 2){
                counterFor2++;
            }
        }
        
        int indexer = counterFor0;
        for(int j=0; j<counterFor0; j++){
            a[j]=0;
        }
        int diff = indexer-
        for(int k=indexer; k<indexer+counterFor1; k++){
            a[k]=1;
            indexer++;
        }
        for(int l=indexer; l<indexer+counterFor2; l++){
            a[l]=2;
        }
        
    }   
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends