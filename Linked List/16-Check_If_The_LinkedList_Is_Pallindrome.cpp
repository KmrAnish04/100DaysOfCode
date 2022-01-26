/*
    Anish's Solution
    Question Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
    
    Complexity Analysis:
    Time: O(N)
    Space: O(1)

    Algorithm By GFG:
        Get the middle of the linked list. 
        Reverse the second half of the linked list. 
        Check if the first half and second half are identical. 
        Construct the original linked list by reversing the second half again and attaching it back to the first half
        Return 1 if list is palindrome else 0.
*/

class Solution{
  public:
  struct Node *reverse(struct Node *head){
        struct Node *pre=NULL;
        struct Node *tmp=head;
        while(tmp!=NULL){
            struct Node *nxt=tmp->next;
            tmp->next=pre;
            pre=tmp;
            tmp=nxt;
        }
        return pre;
    }
    
    void printList(Node* n)
    {
        while(n)
        {
            cout<< n->data << " ";
            n = n->next;
        }
        cout<< endl;
    }
    


    bool areIdentical(struct Node *a,struct Node *b){
        while (a != NULL && b != NULL)
        {
            if (a->data != b->data)
                return false;
     
            /* If we reach here, then a and b are
            not NULL and their data is same, so
            move to next nodes in both lists */
            a = a->next;
            b = b->next;
        }
     
        // If linked lists are identical, then
        // 'a' and 'b' must be NULL at this point.
        return (a == NULL && b == NULL);
    }

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        /*
            My Algorithm:
                Get the middle of the linked list. 
                Reverse the first half of the linked list. 
                Check if the first half and second half are identical. 
                Now, Return 1 if list is palindrome else 0.
        */

        int size=0;
        Node *tmp=head;
        while(tmp!=NULL){
            size++;
            tmp=tmp->next;
        }
        // cout<<"size="<<size<<endl;
        if(size<=1) return true;
        
        tmp=head;    
        Node *midHead=NULL;
        for(int i=1; i<=size/2; i++){
            if(i==size/2){
                midHead=tmp->next;
                tmp->next=NULL;
            }
            tmp=tmp->next;
        }
        // printList(head);
        // printList(midHead);
        
        bool ans=false;
        if(size%2!=0){
            ans=areIdentical(reverse(head), midHead->next);
        }
        else{
            ans=areIdentical(reverse(head), midHead);
        }
        return ans;
    }
};
