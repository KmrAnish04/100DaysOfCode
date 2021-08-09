class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        
        // TC = O(N*log*N)
        // SC = O(1)
        
        int i=0;
        long long Diff = INT_MAX;
        
        sort(a.begin(), a.end());
        
        for(int k=m-1; k<n; k++){
            Diff = min(Diff, (a[k]-a[i++]));
        }
        
        return Diff;
    
    }   
};