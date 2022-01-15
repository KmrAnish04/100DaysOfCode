/*
    Anish's Solution
    Question Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1#
    Time: O(n)
    Space: O(1)
    --This solution can be optimized more.
*/
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node *nthNode;
        Node *kthNode;
        Node *headNode;
        
        int size=0;
        Node *tmpNode = head;
        while(tmpNode != NULL){
            size++;
            if(size == k) kthNode=tmpNode;
            nthNode = tmpNode;
            tmpNode = tmpNode->next;
        }
        headNode = kthNode->next;
        
        if(k == size) return head;
        
        kthNode->next = NULL;
        nthNode->next = head;
        
        return headNode;
    }
};