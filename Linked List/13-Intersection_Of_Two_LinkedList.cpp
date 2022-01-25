/*
    Question Link: https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        map<int,int> mapL1;
        map<int,int> mapL2;
        Node *ans = new Node(-1);
        Node *ansPtr=ans;
        
        Node *temp=head1;
        while(temp!=NULL){
            mapL1[temp->data]++;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            mapL2[temp->data]++;
            temp=temp->next;
        }
        
        temp=head1;
        while(temp!=NULL){
            if(mapL2[temp->data]==1){
                // cout<<"this block"<<endl;
                // cout<<"data value: "<<temp->data<<endl;
                Node *node=new Node(temp->data);
                ansPtr->next=node;
                ansPtr=ansPtr->next;
                mapL2[temp->data]--;
            }
            temp=temp->next;
            // ceout<<"this block1"<<endl;
        }
        
        
        return ans->next;
        
    }
};



// GFG Solution
class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set <int> st;
        while(head2)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }
        
        Node *newHead=NULL, *newTail=NULL;
        
        while(head1)
        {
            if( st.find(head1->data) != st.end() )
            {
                if(newHead==NULL)
                    newHead = newTail = new Node(head1->data);
                else
                {
                    newTail->next = new Node(head1->data);
                    newTail = newTail->next;
                }
            }
            head1 = head1->next;
        }
        
        return newHead;
    }
};
