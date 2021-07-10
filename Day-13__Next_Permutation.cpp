// Solution by "Take U forward" youtube channel
// Link: https://www.youtube.com/watch?v=LuLCLgMElus&t=561s

class Solution {
public:
    void nextPermutation(vector<int>& nums) {   
                
    int sizeOfArray = nums.size()-1;
    
    // Edge cases
    if(nums.size() == 0 || nums.size() == 1){
        nums = nums;
    }
        
    int i = sizeOfArray-1;
    while(i>=0 && nums[i] >= nums[i+1]) i--;
    if(i>=0){
        int j = sizeOfArray;
        while(nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    sort(nums.begin()+i+1, nums.end());
    }   
};