/*
    Problem: Maximum Of All Subarray of size k
    Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

    Complexity Analysis:
        Time: O(N)
        Space: O(k)
*/

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> a;
        deque<int> que;
        // cout<<"top="<<que.back()<<endl;
        // cout<<"front="<<que.front()<<endl;
        
        for(int i=0; i<k; i++){
            while(!que.empty() && arr[i]>=arr[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }
        a.push_back(arr[que.front()]);
        for(int i=k; i<n; i++){
            if(!que.empty() && que.front()==i-k)
                que.pop_front();
            while(!que.empty() && arr[i]>=arr[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            a.push_back(arr[que.front()]);
        }
        
        return a;
    }