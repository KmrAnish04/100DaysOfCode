class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> temp;
	    temp = nums;
	    map<int, int> maps;
	    int count=0;
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i=0; i<temp.size(); i++){
	        maps[temp[i]] = i;
	    }
	    
	    int it=0;
	    while(it<nums.size()){
	        if(temp[it]!=nums[it]){
	            swap(nums[maps[nums[it]]], nums[it]);
	            count++;
	        }
	        else it++;
	    }
	    
	    return count;
	}
};
