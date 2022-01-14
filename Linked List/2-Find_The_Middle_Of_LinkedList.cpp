#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        /*
        	Brute-Force Approch
			Complexity Analysis:
			Time: O(n)
			Space: O(1)
        */
        int ans;
        int size=0;
        Node *tmpNode = head;
        while(tmpNode != NULL){
            size++;
            tmpNode = tmpNode->next;
        }
        
        Node* tmp = head;
        for(int i=1; i<=size; i++){
            if(i==(size/2)+1){
                ans = tmp->data;
                break;
            }
            tmp = tmp->next;
        }
        
        return ans;
    }
};



int main(){

	cout<<"faodf";
	return 0;
}