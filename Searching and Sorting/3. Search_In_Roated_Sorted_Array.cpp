class Solution {
    int find_pivot(vector<int>& nums,int left,int right)
    {
        if(nums[left] < nums[right])
            return 0;
        
        int mid;
        //Iterative binary search
        while(left<right)
        {
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[0])
                right = mid;
            else
                left = mid+1;
        }
        return mid;
    }
    
    int binary_search(vector<int>& nums,int left,int right,int target)
    {
        int mid;
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return -1;
        else if(n==1)
            return nums[0]==target?0:-1;
        
        int pivot = find_pivot(nums,0,n-1);
        if(nums[pivot]==target)
            return pivot;
        
        if(target>=nums[0] && target<=nums[pivot]){
            return binary_search(nums, 0, pivot, target);
        }
        else{
            return binary_search(nums, pivot+1, nums.size()-1, target);
        }
        
        return -1;
    }
};