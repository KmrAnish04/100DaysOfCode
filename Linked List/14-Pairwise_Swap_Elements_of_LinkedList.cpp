/*
    Problem: Pairwise Swap Nodes Of LinkedList
    Question Link:
        GFG: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
        LeetCode: https://leetcode.com/problems/swap-nodes-in-pairs/

    *** Complexity Analysis ***
            Expected Time Complexity: O(N)
            Expected Auxiliary Space: O(1)
*/

// ***GFG Solution***
// This solution is exactly same as the question "Reverse K node in LinkedList", so I used that question's solution with very minor modification.
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        int k=2;
        struct Node *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }
        if(size<=1) return head;

        // Reversing operation 
        int groups=ceil(float(size)/float(k));
        struct Node *curr = head;
        struct Node *pre = NULL;
        struct Node *next = NULL;
        struct Node *newHead = NULL;
        struct Node *preSubHead = NULL;
        
        for (int i = 0; i < groups; i++)
        {   
            // if(curr == NULL) break;
            struct Node *subHead=curr;
            pre = NULL;
            next = NULL;
            int j=1;
            while(curr != NULL && j<=k)
            {
                /* code */
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
                j++;
            }
            
            if(i == 0){
                newHead = pre;
            }
            else{
                preSubHead->next = pre;
            }
            preSubHead=subHead;
        }

        return newHead;
    }
};


// *** LeetCode Solution ***
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int k=2;
        ListNode *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }
        if(size<=1) return head;

        // Reversing operation 
        int groups=ceil(float(size)/float(k));
        ListNode *curr = head;
        ListNode *pre = NULL;
        ListNode *next = NULL;
        ListNode *newHead = NULL;
        ListNode *preSubHead = NULL;
        
        for (int i = 0; i < groups; i++)
        {   
            // if(curr == NULL) break;
            ListNode *subHead=curr;
            pre = NULL;
            next = NULL;
            int j=1;
            while(curr != NULL && j<=k)
            {
                /* code */
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
                j++;
            }
            
            if(i == 0){
                newHead = pre;
            }
            else{
                preSubHead->next = pre;
            }
            preSubHead=subHead;
        }

        return newHead;
    }
};







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





