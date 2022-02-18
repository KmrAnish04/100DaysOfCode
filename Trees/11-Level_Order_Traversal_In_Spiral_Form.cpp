/*
    Problem: Level Order Traversal In Spiral Form or Zig-Zag Traversal
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
        LeetCode: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
        // The question is same but there is a minior difference in traversal direction, but 
        // concept, logic and question is almost same.

    *** Complexity Analysis ***
            Time: O(N)
            Space: O(N)
*/


// *** GFG Solution ***
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> nodes;
    
    nodes.push(root);
    // ans.push_back(root->data);
    bool flag=true;
    
    while(!nodes.empty()){
        vector<int> level;
        int size = nodes.size();
        
        for(int i=0; i<size; i++){
            level.push_back(nodes.front()->data);
            if(nodes.front()->left!=NULL){
                nodes.push(nodes.front()->left);
            }
            if(nodes.front()->right!=NULL){
                nodes.push(nodes.front()->right);
            }
            nodes.pop();
        }
        
        if(flag==true){
            for(int i=level.size()-1; i>=0; i--){
                ans.push_back(level[i]);
            }
            flag=false;
        }
        else{
            for(int i=0; i<level.size(); i++){
                ans.push_back(level[i]);
            }
            flag=true;
        }
        
    }
    
    return ans;
}





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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> nodes;

        nodes.push(root);
        // ans.push_back(root->data);
        bool flag=false;

        while(!nodes.empty()){
            vector<int> level;
            int size = nodes.size();

            for(int i=0; i<size; i++){
                level.push_back(nodes.front()->val);
                if(nodes.front()->left!=NULL){
                    nodes.push(nodes.front()->left);
                }
                if(nodes.front()->right!=NULL){
                    nodes.push(nodes.front()->right);
                }
                nodes.pop();
            }

            if(flag==true){
                vector<int> lev1;
                for(int i=level.size()-1; i>=0; i--){
                    lev1.push_back(level[i]);
                }
                ans.push_back(lev1);
                flag=false;
            }
            else{
                vector<int> lev1;
                for(int i=0; i<level.size(); i++){
                    lev1.push_back(level[i]);
                }
                ans.push_back(lev1);
                flag=true;
            }

        }

        return ans;
    }
};

