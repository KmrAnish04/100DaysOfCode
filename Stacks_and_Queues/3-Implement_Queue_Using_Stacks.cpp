/*
    Problem: Implement Queue data structure using two stacks.
    Question Link: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

    Complexity Analysis:
    Time: 
        For Push operation: O(1)
        For Pop operation: O(N)
    Space: O(1)
*/


class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};

void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code 
        if(s1.empty()) return -1;
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        int popedData=s2.top();
        s2.pop();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        return popedData;
}

