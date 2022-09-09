// *************************** LinkedList ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: https://leetcode.com/problems/rotate-list/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Iterative Approach
            Time Complexity: O(N)
            Space Complexity: O(1)



    Algorithm:
        There is no trick for this question, just find the new head, new tail (make new tail's next point towards NULL) and reconnect the new middle node with previous head node. 
        This is lame approaches which is best for this question.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int sizei=0;
        ListNode *tempNode = head;
        while(tempNode!=NULL){
            sizei++;
            tempNode = tempNode->next;
        }
        
        if(k<=0 || sizei<=0 || sizei==1 ) return head;
        
        k = k%sizei;
        int m = sizei-k; 
        
        if(m == sizei) return head;
        
        ListNode *nthNode;
        ListNode *kthNode;
        ListNode *headNode;
        
        int size=0;
        ListNode *tmpNode = head;
        while(tmpNode != NULL){
            size++;
            if(size == m) kthNode=tmpNode;
            nthNode = tmpNode;
            tmpNode = tmpNode->next;
        }
        headNode = kthNode->next;
        
        
        kthNode->next = NULL;
        nthNode->next = head;
        
        return headNode;
        
    }


    // Almost same approach as above, but with a changed style
    ListNode* rotateRight(ListNode* head, int k) {
        
        int sizei=0;
        ListNode *tempNode = head;
        while(tempNode!=NULL){
            sizei++;
            tempNode = tempNode->next;
        }
        
        if(k<=0 || sizei<=1) return head;
        
        k = k%sizei;
        int m = sizei-k; 
        if(m == sizei) return head;
        
        ListNode *newTail;
        ListNode *newHead;
        ListNode *newMid;
        ListNode *tempNodes=head;
        int size=1;
        
        while(tempNodes){
            if(size==m){
                newTail = tempNodes;
                newHead = tempNodes->next;
            }
            newMid = tempNodes;
            tempNodes = tempNodes->next;
            size++;
        }
        
        newMid->next = head;
        newTail->next = NULL;
        
        
        return newHead; 
        
    }


};