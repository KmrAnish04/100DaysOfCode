Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1!=NULL && head2==NULL) return head1;
    else if(head1==NULL && head2!=NULL) return head2;
    
    
    Node *newHead=NULL;
    Node *tail=NULL;
    if(head1->data<head2->data){
        newHead=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        newHead=head2;
        tail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            tail->next=head1;
            tail=tail->next;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            tail=tail->next;
            head2=head2->next;
        }
    }
    
    if(head1==NULL){
        tail->next=head2;
    }
    else if(head2==NULL){
        tail->next=head1;
    }
    
    return newHead;
}  