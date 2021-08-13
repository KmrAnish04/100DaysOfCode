// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    int size = v.size();
		    int ans, index;
            
		    sort(v.begin(), v.end());
		    
		    if(size%2==0){
		        index = (size-1)/2;
		        ans = (v[index]+v[index+1])/2;
		    }
		    else{
		        index = (size-1)/2;
		        ans = v[index];
		    }
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends