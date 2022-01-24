Node *flatten(Node *root)
{
   // Your code here
   vector<Node*> stack;
   Node *currRoot=root;
   Node *nextPtr=root->next;
   Node *btmPtr=root->bottom;
   Node *preBtmPtr=root;
   
   while(nextPtr!=NULL || btmPtr!=NULL){
       cout<<"currRoot-"<<currRoot->data<<endl;
       cout<<"nextPtr-"<<nextPtr->data<<endl;
       cout<<"btmPtr-"<<btmPtr->data<<endl;
       cout<<"preBtmPtr-"<<preBtmPtr->data<<endl;
    //   cout<<"root-"<<root->data<<endl;
       if(btmPtr==NULL && nextPtr!=NULL){
           btmPtr->bottom=nextPtr;
           currRoot=nextPtr;
       }
       else if((btmPtr!=NULL && nextPtr==NULL) || (btmPtr!=NULL && nextPtr!=NULL)){
            if(nextPtr<btmPtr){
                stack.push_back(btmPtr);
                preBtmPtr->bottom=nextPtr;
                currRoot->next=NULL;
                currRoot=nextPtr;
                
                preBtmPtr=btmPtr;
                nextPtr=root->next;
                btmPtr=root->bottom;
            }
            else{
                preBtmPtr=btmPtr;
                btmPtr=btmPtr->bottom;
            }
        }
        else{
            break;
        }
   }
   
   
}




// Working solution
// Recursive Approch
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
        head1=head1->bottom;
    }
    else{
        newHead=head2;
        tail=head2;
        head2=head2->bottom;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            tail->bottom=head1;
            tail=tail->bottom;
            head1=head1->bottom;
        }
        else{
            tail->bottom=head2;
            tail=tail->bottom;
            head2=head2->bottom;
        }
    }
    
    if(head1==NULL){
        tail->bottom=head2;
    }
    else if(head2==NULL){
        tail->bottom=head1;
    }
    
    return newHead;
}  


Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL) return root;
   
   root->next=flatten(root->next);
   
   return sortedMerge(root, root->next);
   
   
}

