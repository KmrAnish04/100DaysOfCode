class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zeroHead=new Node(-1);
        Node *oneHead=new Node(-1);
        Node *secondHead=new Node(-1);
    
        
        Node *tmpZero=zeroHead;
        Node *tmpOne=oneHead;
        Node *tmpSecond=secondHead;
        
        ///////////////////////////////////////////
        int count0 = 0, count1 = 0, count2 = 0;
        Node*temps = head;
        while(temps!= NULL){
            if(temps->data == 0)
                count0++;
            
            else if(temps->data == 1)
                count1++;
                
            else 
                count2++;
                
            temps = temps->next;
        }
        /////////////////////////////////////////// 
        
        Node *temp=head;
        while(temp!=NULL){
            
            if(temp->data==0){
                tmpZero->next=temp;
                tmpZero=tmpZero->next;
            }
            else if(temp->data==1){
                tmpOne->next=temp;
                tmpOne=tmpOne->next;
            }
            else if(temp->data==2){
                tmpSecond->next=temp;
                tmpSecond=tmpSecond->next;
            }
            
            temp=temp->next;
        }
        
        
        
        if(count0==0 && count1!=0 && count2!=0){
            tmpOne->next=secondHead->next;
            tmpSecond->next=NULL;
            return oneHead->next;
        }
        else if(count0!=0 && count1==0 && count2!=0){
            tmpZero->next=secondHead->next;
            tmpSecond->next=NULL;
            return zeroHead->next;
        }
        else if(count0!=0 && count1!=0 && count2==0){
            tmpZero->next=oneHead->next;
            tmpOne->next=NULL;
            return zeroHead->next;
        }
        else if(count0==0 && count1==0 && count2!=0){
            tmpSecond->next=NULL;
            return secondHead->next;
        }
        else if(count0!=0 && count1==0 && count2==0){
            tmpOne->next=NULL;
            return oneHead->next;
        }
        else if(count0==0 && count1!=0 && count2==0){
            tmpOne->next=NULL;
            return oneHead->next;
        }
        
        
        tmpZero->next=oneHead->next;
        tmpOne->next=secondHead->next;
        tmpSecond->next=NULL;
        return zeroHead->next;
    }
};
