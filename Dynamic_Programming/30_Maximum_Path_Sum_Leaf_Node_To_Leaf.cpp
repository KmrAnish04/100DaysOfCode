// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(N)
        Expected Auxiliary Space: O(Height of Tree)

    Algorithm:

    
*/

// GFG Solution
class Solution {
public:
    // During Sep-2022 this code worked, just below one
    int preOrd(Node *root, int &finalSum){
        if(root==NULL) return INT_MIN;
        if(root && !root->left && !root->right) return root->data;
        
        
        int leftSum = preOrd(root->left, finalSum);
        int rightSum = preOrd(root->right, finalSum);
        
        int currSum=leftSum+rightSum+root->data;
        if(root->left && root->right) finalSum = max(finalSum, currSum);
        
        int nodeSum=max(leftSum, rightSum)+root->data;
        
        return nodeSum;
    }
    
    
    // Before near feburaray 2022, the below solution was working, at that time there was some problem in
    // probleme statement and test cases, that it was considering skew tree test casees also, and at taht 
    // time the below solution i worte was working but now at september 2022 it seems like they improved 
    // the problem statement and now the below solution doesn't work. Now above solution works fine.
    
    // int preOrd(Node *root, int &finalSum){
        
    //     if(root==NULL) return 0;
    //     if(!root->left && !root->right) return root->data;
        
    //     int leftSum;
    //     int rightSum;
    //     int nodeSum;
    //     int currSum;
        
    //     if(root->left && root->right){
    //         leftSum=preOrd(root->left, finalSum);
    //         rightSum=preOrd(root->right, finalSum);
            
    //         nodeSum=max(leftSum, rightSum)+root->data;
    //         if(root->left && root->right){
    //             currSum=leftSum+rightSum+root->data;
    //             if(currSum>finalSum) finalSum=currSum;
    //         }
    //         return nodeSum;
    //     }
        
    //     if(root->right) return preOrd(root->right, finalSum) + root->data;
    //     if(root->left) return preOrd(root->left, finalSum) + root->data;
        
        
    // }
    int maxPathSum(Node* root)
    {
        // code here
        int maxSum=INT_MIN;
        int val=preOrd(root, maxSum);
        
        /*
            The GFG has also included a skew tree in this question's testcases
            which is not valid test case according to the question description,
            but to pass that test case we have include the below condition.
        */
        if(!root->left || !root->right)
            return max(maxSum, val);
        
        return maxSum;
    }
};





// Code Ends Here