/*
    Problem: Check for BST / Validate BST [Check the given tree is BST or not]
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/check-for-bst/1#
        Leetcode: https://leetcode.com/problems/validate-binary-search-tree/

    *** Complexity Analysis ***
        Time: O(N)
        Space: O(1) 
*/

// LeetCode Solution (GFG solution is also same as Leetcode)

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
    bool findBST(TreeNode *root, long long min, long long max){
        
        if(root==NULL) return true;
        
        bool ls;
        bool rs;
        if(root->val>min && root->val<max){
            ls = findBST(root->left, min, root->val);
            rs = findBST(root->right, root->val, max);
        }
        else return false;
        
        if(ls==0 || rs==0) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        long long min=LONG_MIN;
        long long max=LONG_MAX;
        return findBST(root, min, max);
    }
};

