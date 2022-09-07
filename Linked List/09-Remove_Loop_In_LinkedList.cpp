/*
    My Solution
    Question Link GFG: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1 
    Visited-Flag Approch
    Complexity Analysis
    Time: O(N)
    Space: O(1)
*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *tmpNode=head;
        Node *preNode=NULL;
        while(tmpNode!=NULL){
            if(tmpNode->data<0){
                preNode->next=NULL;
                break;
            }
            tmpNode->data *= -1;
            preNode=tmpNode;
            tmpNode=tmpNode->next;
        }
    }
};



/*
    Optimal Approch
    *Floyd's Algorithm* for fiding starting point of loop
*/