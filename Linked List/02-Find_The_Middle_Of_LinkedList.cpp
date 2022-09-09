// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
        Leetcode: https://leetcode.com/problems/middle-of-the-linked-list/
        pepcoding: 
        nados: 

    Complexity Analysis:
            Time Complexity: O(N)
            Space Complexity: O(1)



    Algorithm:
        Two Approaches:
            1. Find length of Linkedlist and then return the middle node (i.e length/2) by iterating till size/2th node.
            2. Use slow and fast pointer technique.
*/




// GFG Solution
// Brute Force Approach
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        /*
        	Brute-Force Approch
			Complexity Analysis:
			Time: O(n)
			Space: O(1)
        */
        int ans;
        int size=0;
        Node *tmpNode = head;
        while(tmpNode != NULL){
            size++;
            tmpNode = tmpNode->next;
        }
        
        Node* tmp = head;
        for(int i=1; i<=size; i++){
            if(i==(size/2)+1){
                ans = tmp->data;
                break;
            }
            tmp = tmp->next;
        }
        
        return ans;
    }
};




// Leetcode Solution
// Fast and Slow Pointer Approach
ListNode* middleNode(ListNode* head) {        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
        
}