/*
    Anish's solution 
    Question Link: GFG- https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
                   LeetCode- https://leetcode.com/problems/add-two-numbers/submissions/

    Complexity Analysis:
    Time: O(max(n,m)), where 'n' is the size of list 1 and 'm' is the size of list 2
    Space: O(n+m)
*/



// Solution for GFG
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    struct Node *reverseLL(struct Node *head){
        struct Node *pre=NULL;
        struct Node *tmp=head;
        while(tmp!=NULL){
            struct Node *nxt=tmp->next;
            tmp->next=pre;
            pre=tmp;
            tmp=nxt;
        }
        return pre;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node *resultant = new Node(-2);
        
        first = reverseLL(first);
        second = reverseLL(second);
        
        struct Node *temp1=first;
        struct Node *temp2=second;
        struct Node *temp3=resultant;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry>0){
            struct Node *newNode = new Node(-1);
            temp3->next=newNode;
            temp3=temp3->next;
            if(temp1!=NULL && temp2==NULL){
                int sum=temp1->data+carry;
                int resultData=sum%10;
                carry=sum/10;
                temp3->data=resultData;
                // if(temp1->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                temp1=temp1->next;
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
            else if(temp1==NULL && temp2!=NULL){
                int sum=temp2->data+carry;
                int resultData=sum%10;
                carry=sum/10;
                temp3->data=resultData;
                // if(temp2->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                temp2=temp2->next;
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
            else{
                int sum;
                if(temp1==NULL && temp2==NULL && carry>0){
                    sum=carry;
                    int resultData=sum%10;
                    carry=sum/10;
                    temp3->data=resultData;
                    break;
                }
                else{
                    sum=temp1->data+temp2->data+carry;
                    int resultData=sum%10;
                    carry=sum/10;
                    temp3->data=resultData;
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
                // if(temp1->next==NULL && temp2->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
        }
        resultant=resultant->next;
        return reverseLL(resultant);
        // return resultant;
    }
};






// Solution for Leetcode
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultant = new ListNode(-2);
        
        ListNode *first = l1;
        ListNode *second = l2;
        
        ListNode *temp1=first;
        ListNode *temp2=second;
        ListNode *temp3=resultant;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry>0){
            ListNode *newNode = new ListNode(-1);
            temp3->next=newNode;
            temp3=temp3->next;
            if(temp1!=NULL && temp2==NULL){
                int sum=temp1->val+carry;
                int resultData=sum%10;
                carry=sum/10;
                temp3->val=resultData;
                // if(temp1->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                temp1=temp1->next;
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
            else if(temp1==NULL && temp2!=NULL){
                int sum=temp2->val+carry;
                int resultData=sum%10;
                carry=sum/10;
                temp3->val=resultData;
                // if(temp2->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                temp2=temp2->next;
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
            else{
                int sum;
                if(temp1==NULL && temp2==NULL && carry>0){
                    sum=carry;
                    int resultData=sum%10;
                    carry=sum/10;
                    temp3->val=resultData;
                    break;
                }
                else{
                    sum=temp1->val+temp2->val+carry;
                    int resultData=sum%10;
                    carry=sum/10;
                    temp3->val=resultData;
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
                // if(temp1->next==NULL && temp2->next==NULL){
                //     temp3->next=NULL;
                //     break;
                // }
                // struct Node *newNode = new Node(-1);
                // temp3->next=newNode;
                // temp3=temp3->next;
            }
        }
        resultant=resultant->next;
        return resultant;
        // return resultant;
    }
};





// Solution by GFG
class Solution
{
    public:
    //Function to reverse the linked list.
    Node* reverse(Node *head) 
    {
        Node * prev = NULL;
        Node * current = head;
        Node * next;
        
        while (current != NULL) 
        { 
            next = current->next;     
            current->next = prev;     
            prev = current;          
            current = next;
        }
        
        return prev; 
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reversing both lists to simplify addition.
        first = reverse(first);             
        second = reverse(second);            
        
        Node *sum=NULL;
        int carry=0;
        
        //using a loop till both lists and carry gets exhausted.
        while( first!=NULL || second!=NULL || carry!=0 )
        {
            //using a variable to store sum of two digits along with carry.
            int newVal = carry;
            
            //if nodes are left in any list, we add their data in newVal.
            if(first) newVal += first->data;
            if(second) newVal += second->data;
        
            //updating carry.
            carry = newVal/10;
            
            //using modulus to store only a single digit at that place.
            newVal = newVal%10;             
            
            //creating new node which gets connected with other nodes that 
            //we get after calculating sum of respective digits.
            Node* newNode = new Node(newVal);
            
            //storing the previously made nodes in the link part of new node.
            newNode->next = sum;
            
            //making the new node as the first node of all previously made node.
            sum = newNode;
            
            //moving ahead in both lists.
            if(first) first = first->next; 
            if(second) second = second->next;
        }
        return sum;
    }
};