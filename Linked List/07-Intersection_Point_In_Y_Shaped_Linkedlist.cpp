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
        **There are two approaches:**
        Both the approaches had almost same time and space complexity, so there is no matter about optimization.

        *Time Complexity: O(n+m) 
        Space Complexity: O(1) *


        **1. Approach-1**

        1, Get the length of the two lists.
        2, Align them to the same start point.
        3, Move them together until finding the intersection point, or the end null



        **2. Approach-2**

        Actually we don't care about the "value" of difference, we just want to make sure two pointers reach the intersection node at the same time.

        We can use two iterations to do that. In the first iteration, we will reset the pointer of one linkedlist to the head of another linkedlist after it reaches the tail node. In the second iteration, we will move two pointers until they points to the same node. Our operations in first iteration will help us counteract the difference. So if two linkedlist intersects, the meeting point in second iteration must be the intersection point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null

        Refer this discuss Section for more details:
        https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!

*/


// Leetcode Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        int size=0;
        
        while(head != NULL){
            size++;
            head = head->next;
        }
        
        return size;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        int n=findLength(head1);
        int m=findLength(head2);

        int maxSize=max(n,m);
        int diff=abs(n-m);
        
        if(n>m){
            for(int i=0; i<diff; i++) head1=head1->next;

        }
        else if(m>n){
            for(int i=0; i<diff; i++) head2=head2->next;
        }
        

        while(head1 && head2){
            if(head1 == head2 && head1 && head2) break;
            
            head1=head1->next;
            head2=head2->next;
        }
         
        
        return head1;
    }
};



/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int findLength(Node* head){
    int size=0;
    
    while(head != NULL){
        size++;
        head = head->next;
    }
    
    return size;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n=findLength(head1);
    int m=findLength(head2);

    int maxSize=max(n,m);
    int diff=abs(n-m);
    
    if(n>m){
        for(int i=0; i<diff; i++) head1=head1->next;

    }
    else if(m>n){
        for(int i=0; i<diff; i++) head2=head2->next;
    }
    

    while(head1 && head2){
        if(head1 == head2 && head1 && head2) break;
        
        head1=head1->next;
        head2=head2->next;
    }
     
    
    return head1->data;
}



// Code Ends Here