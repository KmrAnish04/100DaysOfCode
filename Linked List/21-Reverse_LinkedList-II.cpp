// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1
        Leetcode: https://leetcode.com/problems/reverse-linked-list-ii/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Iterative Approach
            Time Complexity: O(N)
            Space Complexity: O(1)



    Algorithm:
        Refer Discuss Section:

        https://leetcode.com/problems/reverse-linked-list-ii/discuss/2311084/JavaC%2B%2B-Tried-to-Explain-every-step
        https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)
    
*/








// Leetcode Solution

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || left == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        dummy->next = head;
        for(int i = 0; i < left-1;i++) {
            p = p->next;
        }
        ListNode* tail = p->next;
        
        for(int i = 0; i < right-left; i++) {
            ListNode* tmp = p->next;
            p->next = tail->next;
            tail->next = tail->next->next;
            p->next->next = tmp;
        }
        return dummy->next;  
    }
};


// GFG Solution
class Solution
{
    public:
    Node* reverseBetween(Node* head, int left, int right)
    {
        //code here
        if(head == NULL || left == NULL) {
            return head;
        }
        
        Node* dummy = new Node(-1);
        Node* p = dummy;
        dummy->next = head;
        
        for(int i = 0; i < left-1;i++) {
            p = p->next;
        }
        
        Node* tail = p->next;
        
        for(int i = 0; i < right-left; i++) {
            Node* tmp = p->next;
            p->next = tail->next;
            tail->next = tail->next->next;
            p->next->next = tmp;
        }
        return dummy->next;
    }
};

// Code Ends Here