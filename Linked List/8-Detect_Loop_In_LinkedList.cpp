/*
    My Solution
    Question Link GFG: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
    Visited-flag Approch

    Complexity Analysis:
    Time: O(N)
    Space: O(1)

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


/*
    Optimal Approch
    Floyd's Cycle Detection Algorithm
*/