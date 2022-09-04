// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
        Leetcode: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int postOrd(Node *root, int &dia){
        if(root==NULL) return 0;
        
        int ltHt=postOrd(root->left, dia);
        int rtHt=postOrd(root->right, dia);
        
        int currDia=ltHt+rtHt+1;
        int heightOfNode=max(ltHt, rtHt)+1;
        
        if(currDia>=dia) dia=currDia;
        
        return heightOfNode;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int diaOfTree=INT_MIN;
        postOrd(root, diaOfTree);
        return diaOfTree;
    }
};


// Leetcode Solution
class Solution {
public:
    int postOrd(TreeNode *root, int &dia){
        if(root==NULL) return 0;
        
        int ltHt=postOrd(root->left, dia);
        int rtHt=postOrd(root->right, dia);
        
        int currDia=ltHt+rtHt+1;
        int heightOfNode=max(ltHt, rtHt)+1;
        
        if(currDia>=dia) dia=currDia;
        
        return heightOfNode;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diaOfTree=INT_MIN;
        postOrd(root, diaOfTree);
        
        if(diaOfTree==0) return diaOfTree;
        return diaOfTree-1;
    }
};




// Code Ends Here