/*
    Problem: PostOrder Tree Traversal On Binary Tree
    Problem Link: 
        GFG: https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1/#
        Leetcode: https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/

    *** Complexity Analysis ***
        Time: O(N)
        Space: O(1)
*/


/* ********************************* Recursive Solution ********************************* */

// *** GFG Solution ***
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    void postOrd(Node *root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left!=NULL)
            postOrd(root->left, ans);
        if(root->right!=NULL)
            postOrd(root->right, ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        postOrd(node, ans);
        return ans;
    }
};


// *** Leetcode Soluton ***
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
    void postOrd(TreeNode *root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left!=NULL)
            postOrd(root->left, ans);
        if(root->right!=NULL)
            postOrd(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrd(root, ans);
        return ans;
    }
};




/* ********************************* Iterative Solution ********************************* */

// Coming soon....


