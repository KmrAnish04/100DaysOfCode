class Solution {
public:
    int binarySearch(vector<int> array, int x, int low, int high) {
  
        // Repeat until the pointers low and high meet each other
          while (low <= high) {
            int mid = low + (high - low) / 2;

            if (array[mid] == x)
              return mid;

            if (array[mid] < x)
              low = mid + 1;

            else
              high = mid - 1;
          }

          return -1;
    }

    int search(vector<int>& nums, int target) {
        int index = nums.size()-1;
        // int i;
        int ans;
        
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i-1]>nums[i]){
                index=i;
                break;
            }
            else index--;
        }
        
        cout<<"index="<<index<<"\n";
        reverse(nums.begin(), nums.end()-(index-1));
        reverse(nums.begin()+index, nums.end());
        reverse(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
        
        ans = binarySearch(nums, target, 0, nums.size()-1);
        if(ans<0) return -1;
        return ans+index;
    }
};