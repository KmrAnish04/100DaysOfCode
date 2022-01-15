

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *pre = NULL;
        struct Node *curr = head;
        struct Node *next = NULL;
        
        struct Node *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }

        if(size<=1) return head;
        
        for(int i=0; i<size; i++){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        
        return pre;
    }
    
};
    
