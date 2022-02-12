/*
    Problem: Inorder Tree Traversal
    Problem Link: 
        GFG: https://practice.geeksforgeeks.org/problems/inorder-traversal/1
        Leetcode: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

    **** Complexity Analysis ****
            Time: O(N)
            Space: O(1)

*/



/* ******************************** Recursive Approch ******************************** */

// *** GFG Solution **
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void findInorder(Node *root, vector<int> &ans){
        
        if(root->left)
            findInorder(root->left, ans);
        
        ans.push_back(root->data);
        
        if(root->right)
            findInorder(root->right, ans);
        
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        
        if(root==NULL) return ans;
        findInorder(root, ans);
        
        return ans;
    }
};



// *** LeetCode Solution ***
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
    void findInorder(TreeNode *root, vector<int> &ans){
        
        if(root->left)
            findInorder(root->left, ans);
        
        ans.push_back(root->val);
        
        if(root->right)
            findInorder(root->right, ans);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root==NULL) return ans;
        findInorder(root, ans);
        
        return ans;
        
        
    }
};

