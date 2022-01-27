struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};



void MyStack ::push(int x) 
{
    // Your Code
    StackNode *newNode=new StackNode(x);
    newNode->next=top;
    top=newNode;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==NULL)
        return -1;
        
    int popData=top->data;
    StackNode *tmp=top;
    top=top->next;
    // free(tmp);
    delete(tmp);
    return popData;
    
}
