class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        struct Node *newHead=head->next;
        struct Node *pre=NULL;
        struct Node *first=head;
        struct Node *second=head->next;
        struct Node *nxt=head->next->next;
        
        cout<<"pre="<<pre<<endl;
        cout<<"first="<<first<<endl;
        cout<<"second="<<second<<endl;
        cout<<"nxt="<<nxt<<endl;
        int i=1;
        while(nxt!=NULL && nxt->next!=NULL || i<11){
            if(pre==NULL) head=second;
            first->next=nxt;
            second->next=first;
            pre->next=second;
            
            pre=first;
            first=first->next;
            second=first->next;
            nxt=nxt->next;
            i++;
        }
        
        return head;
    }
};