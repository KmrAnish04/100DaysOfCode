class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        long long ans=0;
        unordered_map<long long, int> map;
        long long tempSum=0;
        for(int i=0; i<n; i++){
            tempSum+=arr[i];
            
            if(tempSum==0) ans++;
            ans += map[tempSum];
            map[tempSum]++;
        }
        
        return ans;
    }
};