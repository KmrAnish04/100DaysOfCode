/*
    Problem: BFS traversal on directed Graph
    Question Link: 
        GFG:
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

class Solution 
{
    public:
    
	int minSwaps(vector<int>&nums)
	{	   
        int ans=0;
        vector<pair<int,int>> sortedArr;
        
        for(int i=0; i<nums.size(); i++){
            sortedArr.push_back({nums[i],i});
        }
        sort(sortedArr.begin(), sortedArr.end());
        
        for(int itr=0; itr<sortedArr.size(); itr++){
            int swps=0;
            if(sortedArr[itr].first!=nums[itr]){
                ans++;
                swap(sortedArr[itr],sortedArr[sortedArr[itr].second]);
                itr--;
            }
        }
        
        return ans;
	}
};