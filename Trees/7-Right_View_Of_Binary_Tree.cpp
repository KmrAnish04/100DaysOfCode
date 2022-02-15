/*
    Problem Link: Left view of a Binary Tree
    Question Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

    *** Complexity Analysis ***
        Expected Time Complexity: O(N).
        Expected Auxiliary Space: O(Height of the Tree).
*/


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
    void finder(TreeNode *root, vector<int> &ans, int currLevel){
        
        if(root==NULL) return;
        
        if(ans.size()==currLevel)
            ans.push_back(root->val);        
        
        finder(root->right, ans, currLevel+1);
        finder(root->left, ans, currLevel+1);
        
}
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        finder(root, ans, 0);
        return ans;
        
    }
};