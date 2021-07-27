#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> resultantIntervals;
        if (intervals.size() == 0)
        {
            return intervals;
        }
        if(intervals.size() == 1){
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        
        for (int i = 0; i < intervals.size(); i++)
        {
            if(tempInterval[1] >= intervals[i][0]){
                tempInterval[1] = max(intervals[i][1], tempInterval[1]);
            }
            else
            {
                resultantIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }

        }
        resultantIntervals.push_back(tempInterval);
        return resultantIntervals;
    }
    
};


int main(){
    
    vector<vector<int>> a = {{1,3}, {2,6}, {8,10}, {15,18}};
    
    return 0;
}