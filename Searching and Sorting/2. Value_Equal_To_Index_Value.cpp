class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> ans;
	    for(int i=0; i<n; i++)
	        if(i+1==arr[i]) ans.push_back(i+1);
	    
	    return ans;
	}
};
