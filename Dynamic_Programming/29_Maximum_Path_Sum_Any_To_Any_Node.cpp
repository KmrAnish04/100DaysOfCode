// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
        Leetcode: https://leetcode.com/problems/binary-tree-maximum-path-sum/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/



// GFG Solution
class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int preOrd(Node *root, int &finalSum){
        if(root==NULL) return 0;
        
        // we are avoiding negative sum from both left and right subtree, if any of the subtree gives 
        // negative sum then instead of taking that nagative sum (which will decrease our overall sum), 
        // we'll just ignore that negative sum by taking zero instead of that negative sum.
        int leftSum = max(0, preOrd(root->left, finalSum));
        int rightSum = max(0, preOrd(root->right, finalSum));
        
        
        int currSum=leftSum+rightSum+root->data;
        int nodeSum=max(leftSum, rightSum)+root->data;
        
        if(currSum>finalSum) finalSum=currSum;
        
        return nodeSum;
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int maxSum=INT_MIN;
        preOrd(root, maxSum);
        return maxSum;
    }
};


// Leetcode Solution
class Solution {
public:
    int preOrd(TreeNode *root, int &finalSum){
        if(root==NULL) return 0;
        
        int leftSum = max(0, preOrd(root->left, finalSum));
        int rightSum = max(0, preOrd(root->right, finalSum));
        
        int currSum=leftSum+rightSum+root->val;
        int nodeSum=max(leftSum, rightSum)+root->val;
        
        if(currSum>finalSum) finalSum=currSum;
        
        return nodeSum;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        preOrd(root, maxSum);
        return maxSum;
    }
};



// Code Ends Here