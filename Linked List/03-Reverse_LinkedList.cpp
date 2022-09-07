// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
        Leetcode: https://leetcode.com/problems/reverse-linked-list/submissions/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Iterative Approach
            Time Complexity: O(N)
            Space Complexity: O(1)
        
        Recursive Approach
            Time Complexity: O(N)
            Space Complexity: O(N) i.e stack space used by recursive calls



    Algorithm:
                This question can be solved using Iterative method and Recursive also (Jabardasti Recursion). 

            **Approach 1: Iteratively**

            Complexity analysis

            Time complexity: O(n)
            Space complexity: O(1)

            **Approach 2: Recursive approach**

            Complexity analysis

            Time complexity: O(n)
            Space complexity: O(n) -> cost made by Recursive calls

            Reference: 

            For Iterative Method:
            https://leetcode.com/problems/reverse-linked-list/discuss/803955/C%2B%2B-Iterative-vs.-Recursive-Solutions-Compared-and-Explained-~99-Time-~85-Space

            For Recursive Method:
            https://leetcode.com/problems/reverse-linked-list/discuss/58125/In-place-iterative-and-recursive-Java-solution

    
*/










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

    // Recursive approach, which i found in Leetcode discuss section and I liked it personall, bcoz I wanted
    // to wrote same recursive approach but didn't able to.
    ListNode* reverseList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* newHead = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    

    // The appraoch i wrote.
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* curr= head;
        if(curr==NULL || curr->next==NULL) return curr;
        
        
        ListNode* nxt= curr->next;
        
        while(nxt!=NULL){
            curr->next = pre;
            pre = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        
        curr->next = pre;
        return curr;
    }
    
    
    //The iteravtive approach i found in leetcode discuss section and liked it personally
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = NULL, *nextNode;
        
        while(head){
            nextNode = head->next;
            head->next = preNode;
            preNode = head;
            head = nextNode;
        }
        
        return preNode;
    }
    
    
};


// Code Ends Here