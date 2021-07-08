class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        vector<int> slicing(vector<int>& arr,
                    int X, int Y)
{
  
    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
  
    // To store the sliced vector
    vector<int> result(Y - X + 1);
  
    // Copy vector using copy function()
    copy(start, end, result.begin());
  
    // Return the final sliced vector
    return result;
}
        
        int sizeOfArray = nums.size()-1;
        
        if(nums.size() == 0 || nums.size() == 1){
            nums = nums;
        }
        
        if(nums.size() == 2){
            swap(nums[0], nums[1]);
        }
        
        if(nums[sizeOfArray] > nums[sizeOfArray-1]){
            swap(nums[sizeOfArray], nums[sizeOfArray-1]);
        }
        
        for(int i = sizeOfArray-1; i >= 0; i--){
            vector<int> tempVector;
            if(nums[i] < nums[i+1]){
                swap(nums[i], nums[sizeOfArray]);
                tempVectot = slicing(nums, i+1, sizeOfArray);
                sort(tempVector.begin(), tempVector.end());
            }
        }
        
        for
        
    }
};