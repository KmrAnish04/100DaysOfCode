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



/*

    Algorithm:

        1. Define a variable minEle that stores the current minimum element in the stack. When a minEle is removed fromt he stack, we push “2x – minEle” into the stack instead of x so that previous minimum element can be retrieved using current minEle and its value stored in stack.

        Push(x) : Inserts x at the top of stack.

        If stack is empty, insert x into the stack and make minEle equal to x.
        If stack is not empty, compare x with minEle. Two cases arise:
        If x is greater than or equal to minEle, simply insert x.
        If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.
        Pop() : Removes an element from top of stack.

        Remove element from top. Let the removed element be y. Two cases arise:
        If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
        If y is less than minEle, the minimum element now becomes (2*minEle – y), update (minEle = 2*minEle – y). Now retrieve previous minimum from current minimum and its value in stack.


*/

// Solution by GFG
class Solution{
    int minEle;
    stack<int> s;
    public:
       int getMin(){
           if(s.empty()){
             return -1;
           }
           else{
             return minEle;
           }
       }
       int pop(){
           if(s.empty()){
                return -1;
            }
            int t = s.top();
            s.pop();
            if(t<minEle)
            {
                int k = minEle;
                minEle = 2*minEle-t;
                return k;
            }
            else{
                return t;
            }
       }
       void push(int x){
           if(s.empty())
           {
             minEle =x ;
             s.push(x);
             return ;
            }
            if(x<minEle)
            {
                s.push(2*x-minEle);
                minEle = x;
            }
            else{
                s.push(x);
            }
       }
};
