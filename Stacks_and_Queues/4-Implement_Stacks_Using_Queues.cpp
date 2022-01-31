/*
    Problem: Implement stacks data structure using two queues
    Question Link: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

    Complexity Analysis:
        Time: 
            For Push Operation: O(1)
            For Pop Operation: O(N)
        Space: O(1)
*/



class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

// My Solution (need to be more accurate yet [only 14% accurate shown by GFG platform])
int QueueStack :: pop()
{
        // Your Code   
        if(q1.empty()) return -1;
        
        if(q1.size()==1){
            int data=q1.front();
            q1.pop();
            return data;
        }
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        
        int size=q2.size();
        for(int i=0; i<size-1; i++){
            q1.push(q2.front());
            q2.pop();
        }
        
        int popedData=q2.front();
        q2.pop();
        
        return popedData;
}



/* 
    Algorithm:
        For push operation:
            Store all elements of first queue into second queue and keep removing them from first queue.
            First queue is empty now so push the given number into first queue.
            Then again store all elements of second queue into first queue back and keep removing them from second queue.
            For pop operation:

            If the first queue is not empty, store the front element from the queue in a variable and pop that element. Return the popped element.
            Else return -1.
*/

// Solution by GFG
//Function to push an element into stack using two queues.
void push(struct Queue *q1,struct Queue *q2,int num)
{
    //while first queue is not empty, we keep popping the front element
    //from first queue and storing that element in second queue.
    while(!isEmpty(q1))
    {
        int k = front(q1);
        
        //popping element from first queue.
        dequeue(q1);
        
        //pushing it into second queue.
        enqueue(q2,k);
    }
    
    //q1 is empty now and we push the given number into first queue.
    enqueue(q1,num);
    
    //while second queue is not empty, we keep popping the front element
    //from second queue and storing that element in first queue.
    while(!isEmpty(q2))
    {
        int k = front(q2);
        //popping element from second queue.
        dequeue(q2);
        
        //pushing it into first queue.
        enqueue(q1,k);
    }
}

//Function to pop an element from stack using two queues. 
int pop(struct Queue *q1)
{
    if(!isEmpty(q1))
    {
        //we store the front element from the queue in a 
        //variable and pop that element.
        int r = front(q1);
        dequeue(q1);
        
        //returning the popped element.
        return r;
    }
    //else we return -1.
    return -1;
}