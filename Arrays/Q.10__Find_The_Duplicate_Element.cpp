class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;

        // sorting the array first
        sort(nums.begin(),nums.end());

        // afer sorting the repeated or duplicate elements come at adjecent positions
        for(int i=0; i<nums.size()-1; i++){

            // checkig the adjecent elements are repeated or not, if repeated then return that element as answer
            if(nums[i] == nums[i+1]){
                ans = nums[i];
            }
        }
        return ans;
    }
};