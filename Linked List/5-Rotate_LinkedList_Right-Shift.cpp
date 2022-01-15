/*
    Anish's Solution
    Question Link: https://leetcode.com/problems/rotate-list/
    Time: O(n)
    Space: O(1)
    --This solution can be optimized more.
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
};