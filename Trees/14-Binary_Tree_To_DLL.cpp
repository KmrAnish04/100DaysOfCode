/*
    Problem: Convert Binary Tree To Doubly LinkedList/Convert Binary Search Tree to Sorted Doubly Linkedlist
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
        Leetcode: 'availble for premium users'

    *** Complexity Analysis ***
            Time: O(N)
            Space: O(1)

    *** Algorithms (By GFG) ***
        The idea is to do inorder traversal of the binary tree. 
        While doing inorder traversal, keep track of the previously 
        visited node in a variable say prev. For every visited node, 
        make it next of prev and previous of this node as prev.

*/



// *** GFG Solution ***
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    void inOrd(Node* root, Node* &head, Node* &pre){
        
        if(root==NULL) return;
        
        inOrd(root->left, head, pre);
        if(pre!=NULL){
            pre->right=root;
            root->left=pre;
            pre=root;
        }
        else{
            head=root;
            pre=root;
        }
        inOrd(root->right, head, pre);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head=NULL;
        Node* pre=NULL;
        
        inOrd(root, head, pre);
        
        return head;
    }
};



