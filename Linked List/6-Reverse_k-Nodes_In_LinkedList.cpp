#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method

        // Finding the size of LikedList
        struct node *tmp = head;
        int size = 0;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }
        if(size<=1) return head;

        // Reversing operation
        int groups=ceil(size/k);
        struct node *curr = head;
        struct node *ansNode=NULL;
        struct node *pre = NULL;
        struct node *next = NULL;
        struct node *newHead = NULL;

        for (int i = 0; i < groups; i++)
        {   
            pre = NULL;
            next = NULL;
            struct node *subHead = curr;
            cout<<"subhead: "<<subHead->data<<endl;
            int j=1;
            while(curr != NULL && j<=k)
            {
                /* code */
                next = curr->next;
                curr->next = pre;
                pre = curr;
                ansNode = curr;
                curr = next;
                j++;
            }
            cout<<"pre: "<<pre->data<<endl;
            subHead->next = pre;
            // cout<<"subhead: "<<subHead->data;
            if(i == 0){
                newHead = pre;
                cout<<"newHead: "<<newHead<<endl;
                cout<<"IF Condition"<<endl;
            }
            cout<<"newHead1: "<<newHead<<endl;
            cout<<"i: "<<i<<endl;
        }

        return newHead;
    }
};




int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}
