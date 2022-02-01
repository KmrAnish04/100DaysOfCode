/*
    Problem: Get Minimum element from stack
    Question Link: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1#

    Complexity Analysis:
        Time: O(1) [for all three operations i.e pusp(), pop(), getMin()]
        Space: O(1)
*/

// My Solution (need to be more optimized code, 8% accurate)
class Solution
{
    stack<int> s;
    int mini;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (s.empty())
            return -1;
        return mini;
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (s.empty())
            return -1;
        else
        {

            int data = s.top();
            if (data < mini)
            {
                int res = mini;
                mini = (2 * mini) - data;
                s.pop();
                return res;
            }
            else
            {
                s.pop();
                return data;
            }
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {

        // Write your code here
        if (s.empty())
        {
            mini = x;
            s.push(x);
        }
        else
        {
            if (x < mini)
            {
                int data = (2 * x) - mini;
                s.push(data);
                mini = x;
            }
            else
                s.push(x);
        }
    }
};