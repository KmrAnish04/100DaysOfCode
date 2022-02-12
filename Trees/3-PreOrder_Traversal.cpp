/*
    Problem: Preorder Traversal
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/preorder-traversal/1#
        Leetcode: https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

    ***** Complexity Analysis *****
        Time: O(N)
        Space: O(1)
*/




/* ************************ Recursion Approch ************************ */


// ** GFG Solution **
/*
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

//Function to return a list containing the preorder traversal of the tree.
void preOrd(Node *root, vector<int> &ans){
    
    // cout<<root->val;
    ans.push_back(root->data);
    if(root->left!=NULL){
        preOrd(root->left, ans);
    }
    if(root->right!=NULL){
        preOrd(root->right, ans);
    }
}
vector <int> preorder(Node* root)
{
  vector<int> ans;
  // Your code here
  if(root==NULL) return {};
  preOrd(root, ans);
  return ans;
}


// ** LeetCode Solution  **
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
    vector<int> ans;
    void preOrd(TreeNode *root){
        
        // cout<<root->val;
        ans.push_back(root->val);
        if(root->left!=NULL){
            preOrd(root->left);
        }
        if(root->right!=NULL){
            preOrd(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        preOrd(root);
        return ans;
    }
};

