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