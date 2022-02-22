/*
    Problem: Symmetric Tree
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/symmetric-tree/1
        Leetcode: https://leetcode.com/problems/symmetric-tree/

    *** Complexity Analysis ***
            Expected Time Complexity: O(N).
            Expected Auxiliary Space: O(Height of the Tree).
            
    
    *** Algortihm ***
        Anish's Solution:
        The idea is to treat the given tree as a two different trees, the root 
        of first tree 'T1' will be the first left child of origional tree (i.e root->left) 
        and root of second tree say 'T2' will be first right child of origional tree (i.e root->right).
        Now, traverse the first tree with pre-order traversal and simultanously 
        traverse the second tree with reverse pre-order traversal(i.e right, left, root) 
        and compare the nodes data of both trees with each other. At any point you get a node whose 
        data is not matching then the tree is not symmertric Tree. Otherwise tree is 
        symmetric if the both tree nodes's data is matching.

        GFG Algorithm:
        Maintain two Node pointers in the tree.
        If the first moves right, the other moves left.
        If the first moves left, the other moves right.

        And, for every pair of node we get through the above traversal, we check the following:
        if node1 is NULL and node2 is not NULL: The tree is not symmetric, return False.
        If node1 is not NULL and node2 is NULL: The tree is not symmetric, return False.
        If both node1 and node2 are NULL: Return True.
        If both node1 and node2 are not NULL: Return ((node->data == node2->data) && (isSymm (node1->left, node2->right) && (isSymm (node1->right, node2->left))

*/





// *** GFG Solution ***
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    void preOrd(Node *root1, Node *root2, bool &isTreeStillIden){
        if(root1==NULL && root2==NULL) return;
        
        if(root1 && root2 && root1->data==root2->data){
            if(isTreeStillIden){
                preOrd(root1->left, root2->right, isTreeStillIden);
            }
            if(isTreeStillIden){
                preOrd(root1->right, root2->left, isTreeStillIden);
            }
        }
        else{
            isTreeStillIden=false;
            return;
        }
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    bool isOpen=true;
	    if(root==NULL) return true;
	    if(root!=NULL && root->left==NULL && root->right==NULL) return true;
	    preOrd(root->left, root->right, isOpen);
	    return isOpen;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrd(TreeNode *root1, TreeNode *root2, bool &isTreeStillIden){
        if(root1==NULL && root2==NULL) return;
        
        if(root1 && root2 && root1->val==root2->val){
            if(isTreeStillIden){
                preOrd(root1->left, root2->right, isTreeStillIden);
            }
            if(isTreeStillIden){
                preOrd(root1->right, root2->left, isTreeStillIden);
            }
        }
        else{
            isTreeStillIden=false;
            return;
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool isOpen=true;
	    if(root==NULL) return true;
	    if(root!=NULL && root->left==NULL && root->right==NULL) return true;
	    preOrd(root->left, root->right, isOpen);
	    return isOpen;
    }
};




