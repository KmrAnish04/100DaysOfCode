/*
    Question Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
    The below is iterative approch, there is a recursive approch, try that also.
    // Complexity Analysis:
        Time: O(n)
        Space: O(1)
*/


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
        int groups=ceil(float(size)/float(k));
        struct node *curr = head;
        struct node *pre = NULL;
        struct node *next = NULL;
        struct node *newHead = NULL;
        struct node *preSubHead = NULL;
        
        for (int i = 0; i < groups; i++)
        {   
            // if(curr == NULL) break;
            struct node *subHead=curr;
            pre = NULL;
            next = NULL;
            int j=1;
            while(curr != NULL && j<=k)
            {
                /* code */
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
                j++;
            }
            
            if(i == 0){
                newHead = pre;
            }
            else{
                preSubHead->next = pre;
            }
            preSubHead=subHead;
        }

        return newHead;
    }
};




int main(void)
{
    // Code
    return(0);
}
