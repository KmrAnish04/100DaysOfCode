class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans;
        int tmpProd=1;
        int rightProd=nums[n-1];
        
        for(int i=0; i<n; i++){
            tmpProd *= nums[i];
            ans.push_back(tmpProd);
        }
        
        for(int i=n-1; i>=0; i--){
            
            if(i==n-1) ans[i]=ans[i-1];
            else if(i==0) ans[i]=rightProd;
            else{
                ans[i]=ans[i-1]*rightProd;
                rightProd *= nums[i];
            }
        }
        
        
        return ans;
        
        
    }
};

