// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
        Leetcode: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
        pepcoding: 
        nados:

        There is a slight difference in GFG and Leetcode question, you can visit both qustions. Thats why there is slight differnce in code and logic also. 

    Complexity Analysis:
        Time Complexity: O(N)
        Space Complexity: O(1)



    Algorithm:

*/



/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
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
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        // Finding the size of LikedList
        struct node *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }
        if(size<=1) return head;

        // Reversing operation 
        int groups=ceil(float(size)/float(k));
        struct node *curr = head;
        struct node *pre = NULL;
        struct node *next = NULL;
        struct node *newHead = NULL;
        struct node *preSubHead = NULL;
        
        for (int i = 0; i < groups; i++)
        {   
            // if(curr == NULL) break;
            struct node *subHead=curr;
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
}





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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next == NULL || k==1) return head;
        
        ListNode *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }

        // Reversing operation starts from here
        int groups=floor(float(size)/float(k)); // No. of groups or sub-lists which we need to reverse in the whole linkedlist
        
        // Variables explaination
        // *curr -> current node
        // *pre -> previous node to current node
        // *next -> next node to current ndoe
        // *newHead -> head node of newly modified/reversed list
        // *preSubHead -> head node of just previous group which we reversed
        
        ListNode *curr = head, *pre, *next, *newHead, *preSubHead;
        
        for (int i = 0; i < groups; i++)
        {   
            ListNode *subHead=curr; // head node of current group which we are reversing currently
            pre = NULL;
            next = NULL;
            
            for(int j=1; j<=k && curr != NULL; j++)
            {
                // Same logic as question "Reverse Linkedlist"
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            
            if(i == 0) newHead = pre; // if current group/sub-list is first group which we reversed above then its head node is our new head of whole reversed/modified list.
            
            else preSubHead->next = pre; // linking groups with each other
            
            preSubHead=subHead; // keeping track of head node of current group/sub-list which we reversed above so that we will be able to link sub-lists together easily
        }
        
        // linking remained/left sub-lists which are of size less than k or sub-lists which are not part of k groups
        if(curr!=NULL) preSubHead->next = curr;

        return newHead;
    }
};


// Code Ends Here