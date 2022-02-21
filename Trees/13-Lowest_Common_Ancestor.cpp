/*
    Problem: Find common lowest ancestor of the given node
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
        Leetcode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

    *** Complexity Analysis ***
            Time: O(N)
            Space: O(N)

    *** Algorithms (By GFG) ***
        **Method-I:**
            Using a container like stack or queue, and store all 
            the nodes until we find the required node, when we found 
            the required node then push that node also and then stop 
            pushing nodes. Do the pushing opertion for both 'p' and 'q' 
            and store all the nodes of 'p' and 'q' in two different 
            containers. Now iterate the contaniers from the top, when 
            you find the common nodes in both the containers then stop 
            iteration and that common node will be your answer.

        **Method-II**
            Optimized Approch
            Time: O(N)
            Space: O(1)

            Solution: https://www.youtube.com/watch?v=_-QHfMDde90&t=626s

*/


// Solved with method-I

// *** GFG Solution ***
void preOrd(Node* root, int reqNodeVal, deque<Node*> &que, bool &isStkOpen){
        
        
        if(root==NULL && !que.empty() && isStkOpen==true){
            // que.pop_back();
            return;
        }
        
        if(root==NULL && que.empty()) return;
        
        if(isStkOpen==true){
            if(root->data!=reqNodeVal){
                que.push_back(root);
                if(root->left!=NULL){
                    preOrd(root->left, reqNodeVal, que, isStkOpen);
                    if(isStkOpen==true && !que.empty()) que.pop_back();
                }
                if(root->right!=NULL){
                    preOrd(root->right, reqNodeVal, que, isStkOpen);
                    if(isStkOpen==true && !que.empty()) que.pop_back();
                }
            }
            else{
                que.push_back(root);
                isStkOpen=false;
                return;
            }
        }
    }
    

//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int p, int q)
{
   //Your code here
        deque<Node*> queP;
        deque<Node*> queQ;
        bool isOpenP=true;
        bool isOpenQ=true;
        unordered_map<int,int> maps;
        Node* ans;
        preOrd(root, p, queP, isOpenP);
        preOrd(root, q, queQ, isOpenQ);
        
        
        // cout<<"size of queP: "<<queP.size()<<endl;
        for(int i=0; i<queP.size(); i++){
            maps[queP[i]->data]=1;
            // cout<<"queP ele: "<<queP[i]->val<<endl;
        }
        
        // cout<<"size of queQ: "<<queQ.size()<<endl;
        // for(int i=0; i<queQ.size(); i++){
        //     // maps[queQ[i]->val]=1;
        //     cout<<"queQ ele: "<<queQ[i]->val<<endl;
        // }
        // cout<<"size of queQ: "<<queQ.size()<<endl;
        int size=queQ.size();
        for(int i=0; i<size; i++){
            // cout<<"queQ ele: "<<queQ[i]->val<<endl;
            if(maps[queQ.back()->data]==1){
                return queQ.back();
                // break;
            }
            else queQ.pop_back();
            // cout<<"queQ ele: "<<queQ[i]->val<<endl;
        }
        
        return ans;
}



// *** Leetcode Solution ***
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preOrd(TreeNode* root, int reqNodeVal, deque<TreeNode*> &que, bool &isStkOpen){
        
        
        if(root==NULL && !que.empty() && isStkOpen==true){
            // que.pop_back();
            return;
        }
        
        if(root==NULL && que.empty()) return;
        
        if(isStkOpen==true){
            if(root->val!=reqNodeVal){
                que.push_back(root);
                if(root->left!=NULL){
                    preOrd(root->left, reqNodeVal, que, isStkOpen);
                    if(isStkOpen==true && !que.empty()) que.pop_back();
                }
                if(root->right!=NULL){
                    preOrd(root->right, reqNodeVal, que, isStkOpen);
                    if(isStkOpen==true && !que.empty()) que.pop_back();
                }
            }
            else{
                que.push_back(root);
                isStkOpen=false;
                return;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> queP;
        deque<TreeNode*> queQ;
        bool isOpenP=true;
        bool isOpenQ=true;
        unordered_map<int,int> maps;
        TreeNode* ans;
        preOrd(root, p->val, queP, isOpenP);
        preOrd(root, q->val, queQ, isOpenQ);
        
        
        // cout<<"size of queP: "<<queP.size()<<endl;
        for(int i=0; i<queP.size(); i++){
            maps[queP[i]->val]=1;
            // cout<<"queP ele: "<<queP[i]->val<<endl;
        }
        
        // cout<<"size of queQ: "<<queQ.size()<<endl;
        // for(int i=0; i<queQ.size(); i++){
        //     // maps[queQ[i]->val]=1;
        //     cout<<"queQ ele: "<<queQ[i]->val<<endl;
        // }
        // cout<<"size of queQ: "<<queQ.size()<<endl;
        int size=queQ.size();
        for(int i=0; i<size; i++){
            // cout<<"queQ ele: "<<queQ[i]->val<<endl;
            if(maps[queQ.back()->val]==1){
                return queQ.back();
                // break;
            }
            else queQ.pop_back();
            // cout<<"queQ ele: "<<queQ[i]->val<<endl;
        }
        
        return ans;
    }
};

