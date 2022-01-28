




// This solution that I thought but not working now, it is near to be a right solution. I will correct it later
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
        
        // cout<<"pre="<<pre->data<<endl;
        cout<<"first="<<first->data<<endl;
        cout<<"second="<<second->data<<endl;
        cout<<"nxt="<<nxt->data<<endl;
        int i=1;
        while(nxt!=NULL){
            if(pre==NULL){
                
                cout<<"i="<<i<<endl;
                cout<<"In if block"<<endl;
                cout<<"first="<<first->data<<endl;
                cout<<"second="<<second->data<<endl;
                cout<<"nxt="<<nxt->data<<endl;
                second->next=first;
                first->next=nxt;
                newHead=second;
                pre=newHead;
            }
            else{
                cout<<"i="<<i<<endl;
                cout<<"In else block"<<endl;
                cout<<"pre="<<pre->data<<endl;
                cout<<"first="<<first->data<<endl;
                cout<<"second="<<second->data<<endl;
                cout<<"nxt="<<nxt->data<<endl;
                
                
                second->next=first;
                first->next=nxt;
                pre->next=second;
            }
            // first->next=nxt;
            // second->next=first;
            // pre->next=second;
            
            pre=first;
            first=pre->next;
            second=first->next;
            nxt=second->next;
            i++;
            
            // cout<<"pre="<<pre->data<<endl;
            // cout<<"first="<<first->data<<endl;
            // cout<<"second="<<second->data<<endl;
            // cout<<"nxt="<<nxt->data<<endl;
            // i++;
        }
        
        return newHead;
    }
};