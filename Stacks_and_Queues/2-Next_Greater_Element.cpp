/*
    Problem: Next Greater Element
    Question Link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

    Complexity Analysis:
    Time: O(N)
    Space: O(N)

    Algorithm:
        Traverse the array from last element in backward direction.
            For each iteration,
            While element at top of stack is less than or equal to current array element, pop elements from the stack.
            If stack becomes empty, store -1 in the answer list else store the top element of the stack.  
            Push the current array element into the stack.

*/

// My Solution
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<long long> stk;
        stk.push(arr[n-1]);
        
        int i=n-2;
        while(i>=0){
            if(stk.empty()){
                stk.push(arr[i]);
                arr[i]=-1;
                i--;
            }
            else if(arr[i]<stk.top()){
                long long curEle=arr[i];
                arr[i]=stk.top();
                stk.push(curEle);
                i--;
            }
            else{
                stk.pop();
            }
        }
        
        arr[n-1]=-1;
        
        return arr;
    }
};



// GFG Solution
// Function to return Next larger elements

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long > s;
        vector<long long > res (n);
        
        //traversing the array from last element in backward direction.
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.   
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
            
            //pushing the current array element into the stack.  
            s.push (arr[i]);
        }
        //returning the list.
        return res;
    }
};