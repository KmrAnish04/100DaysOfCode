class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size()-3; i++){
            
            for(int j=i+1; j<arr.size()-2; j++){ 
                
                int left=j+1;
                int right=arr.size()-1;
                int found=false;
                
                while(left<right){
                    
                    int tripSum = arr[i]+arr[j]+arr[left]+arr[right];
                    
                    if(tripSum==k){
                        vector<int> quad = {arr[i], arr[j], arr[left], arr[right]};
                        res.push_back(quad);
                        while(left<right && arr[left]==arr[left+1]) left++;
                        while(left<right && arr[right]==arr[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(tripSum<k) left++;
                    else if(tripSum>k) right--;
                    
                }
                
                while(j+1<arr.size() && arr[j+1]==arr[j]) j++;
                
            }
            while(i+1<arr.size() && arr[i+1]==arr[i]) i++;
        }
        
        return res;
    }
};