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
