// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
        Leetcode: https://leetcode.com/problems/linked-list-cycle/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Time Complexity: O(N)
        Space Complexity: O(1)



    Algorithm:
        Generally, there is only one approach for this question, but If we modifiy the constraints of 
        node value little bit then we can say that there are two approaches, Like if node value constraints 
        are 0>=value<=10^5, means if nodes only contains positive value, then approach-1 will works otherwise 
        approach-2 will work in both cases (i.e whether value is poistive or negative).

        **Approach-1** (this approach works for GFG bcoz in GFG, node value contraints are 0>=Value<=10^5)
        1. Iterate the list from starting and at every node make its value -1 or something which is invalid value,

        2. Then if there will be any loop in the list, then you will reach at an already visited node at any iteration, 
           then by checking its value (that will be -1 or invalid value that you stored during iteration) you will get to know
           that this node is already visited, then it means there is a loop then return true.

        3. But if there is no loop in the list, then you will automatically reach the null, so return false.



        **Approach-2** (This apparoch will work for both GFG and Leetcode)
        Best and efficient approach: Using slow and fast pointer,
        Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"
        Approach: This is the fastest method and has been described below:

        1. Traverse linked list using two pointers.

        2. Move one pointer(slow) by one and another pointer(fast_) by two.

        3. If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.

        Time Complexity: O(N)
        Space Complexity: O(1)




*/





// GFG Solution

/*
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *tmpNode=head;
        bool isLoop=false;
        while(tmpNode!=NULL){
            if(tmpNode->data<0){
                isLoop=true;
                break;
            }
            tmpNode->data*=-1;
            tmpNode=tmpNode->next;
        }
        
        return isLoop;
    }
};



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

    bool hasCycle(ListNode *head){
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast && fast->next){            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
            
        }
        
        return false;
    }
    
};

// Code Ends Here