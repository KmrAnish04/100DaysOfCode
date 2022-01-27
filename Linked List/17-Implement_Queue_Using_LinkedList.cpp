struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};


void MyQueue:: push(int x)
{
        // Your Code
        QueueNode *newNode=new QueueNode(x);
        if(rear==NULL && front==NULL)
            rear=front=newNode;
        else{
            rear->next=newNode;
            rear=newNode;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code    
        if(front==NULL)
            return -1;
        
        int popData=front->data;
        QueueNode *popNode = front;
        
        if(front==rear)
            front=rear=NULL;
        else
            front=front->next;
        
        
        delete(popNode);
        return popData;
}
