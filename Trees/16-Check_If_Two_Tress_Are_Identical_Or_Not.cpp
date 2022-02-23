/*
    Problem: Determine if Two Trees are Identical
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
        Leetcode: https://leetcode.com/problems/same-tree/

    *** Complexity Analysis ***
           Expected Time Complexity: O(N).
           Expected Auxiliary Space: O(Height of the Tree).
            
    
    *** Algortihm ***
        Two trees are identical when they have same data and arrangement of data is also same. 
        To identify if two trees are identical, we need to traverse both trees simultaneously, 
        and while traversing we need to compare data and children of the trees.
 

*/


// *** GFG Solution ***
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
    void preOrd(Node *root1, Node *root2, bool &isTreeStillIden){
        if(root1==NULL && root2==NULL) return;
        
        if(root1 && root2 && root1->data==root2->data){
            if(isTreeStillIden){
                preOrd(root1->left, root2->left, isTreeStillIden);
            }
            if(isTreeStillIden){
                preOrd(root1->right, root2->right, isTreeStillIden);
            }
        }
        else{
            isTreeStillIden=false;
            return;
        }
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        bool isIden=true;
        
        preOrd(r1,r2, isIden);
        
        return isIden;
    }
};


// *** Leetcode Solution ***
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
    void preOrd(TreeNode *root1, TreeNode *root2, bool &isTreeStillIden){
        if(root1==NULL && root2==NULL) return;
        
        if(root1 && root2 && root1->val==root2->val){
            if(isTreeStillIden){
                preOrd(root1->left, root2->left, isTreeStillIden);
            }
            if(isTreeStillIden){
                preOrd(root1->right, root2->right, isTreeStillIden);
            }
        }
        else{
            isTreeStillIden=false;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isIden=true;
        preOrd(p, q, isIden);
        return isIden;
    }
};



