/*
    Problem: Level Order Traversal
    Problem LinkL:
            GFG: https://practice.geeksforgeeks.org/problems/level-order-traversal/1
            LeetCode: https://leetcode.com/problems/binary-tree-level-order-traversal/


    *** Complexity Analysis: ***
        Time: O(N)
        Space: O(N)

*/


// *** GFG Solution ***

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

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      queue<Node*> nodeQue;
      
      if(node==NULL) return ans;
      
      nodeQue.push(node);
      while(!nodeQue.empty()){
          
          Node *front = nodeQue.front();
          ans.push_back(front->data);
          if(front->left != NULL){
              nodeQue.push(front->left);
          }
          if(front->right != NULL){
              nodeQue.push(front->right);
          }
          
          nodeQue.pop();
      }
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> nodeQue;
        
        if(root==0)
            return ans;
        
        nodeQue.push(root);
        
        while(!nodeQue.empty()){
            
            vector<int> level;
            int sizeOfQue = nodeQue.size();
            
            for(int i=0; i<sizeOfQue; i++){
                TreeNode *queFront = nodeQue.front();
                level.push_back(queFront->val);
                if(queFront->left!=NULL){
                    nodeQue.push(queFront->left);
                }
                if(queFront->right!=NULL){
                    nodeQue.push(queFront->right);
                }
                nodeQue.pop();
                
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};

