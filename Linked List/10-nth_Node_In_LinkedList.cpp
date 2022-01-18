/*
    My Solution 
    Question Link GFG: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#
    Time: O(N)
    Space: O(1)
*/
// Approch 1
/*
    First approach is to calculate the length of the linked list (L)and subtract n(position from the back) from it to get the position of the desired node from the front.
*/
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int nthNodeFromFront;
       int size=0;
       int ans;
       Node *tmpNode=head;
       while(tmpNode!=NULL){
           size++;
           tmpNode=tmpNode->next;
       }
       
       if(n>size) return -1;
       
       nthNodeFromFront=size-n;
       tmpNode=head;
       for(int i=0; i<nthNodeFromFront; i++){
           tmpNode=tmpNode->next;
       }
       ans=tmpNode->data;
       
       return ans;
}

// Approch 2
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int size=0;
       int ans;
       int cnt;
       Node *tmpNode=head;
       while(tmpNode!=NULL){
           size++;
           tmpNode=tmpNode->next;
       }
       
       if(n>size) return -1;
       
       cnt=size;
       tmpNode=head;
       while(tmpNode!=NULL){
           if(n==cnt){
               ans=tmpNode->data;
               break;
           }
           cnt--;
           tmpNode=tmpNode->next;
       }
       
       return ans;
}


// Approch 3
/*
    **Optimal Approch**
    Algorithm: 
    Another approach is to use two pointers. Both pointers are initialized to head. Traverse n nodes from head with first pointer. 
    Then the second pointer and the first pointer start moving simultaneously. This keeps on going till the first pointer becomes null. 
    At this point the second pointer will be at the desired node i.e. at nth node from end since the first pointer had traversed n elements 
    previously and thus had difference of n nodes with second pointer.
*/

int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *leftPointer=head;
       Node *rightPointer=head;
       
       for(int i=0; i<n; i++){
           if(rightPointer==NULL) return -1;
           rightPointer=rightPointer->next;
       }
       
       while(rightPointer!=NULL){
           rightPointer=rightPointer->next;
           leftPointer=leftPointer->next;
       }
       
       return leftPointer->data;
}