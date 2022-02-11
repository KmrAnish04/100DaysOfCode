class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> nodeQue;
        
        if(root==0)
            return ans;
        
        nodeQue.push(root);
        int currLevel=0;
        
        while(!nodeQue.empty()){
            
            vector<int> level;
            TreeNode *queFront = nodeQue.front();
            
            if(queFront==root){
                ans.push_back({queFront->val});
                
                if(queFront->left!=NULL){
                    nodeQue.push(queFront->left);
                    level.push_back(queFront->left->val);
                }
                if(queFront->right!=NULL){
                    nodeQue.push(queFront->right);
                    level.push_back(queFront->right->val);
                }
                nodeQue.pop();
                ans.push_back(level);
                currLevel++;
                
            }
            else{
                for(int i=0; i<pow(2,currLevel); i++){
                    TreeNode *front=nodeQue.front();
                    // if(front->left==NULL) cout<<"left="<<front->left<<endl;
                    if(front->left != 0){
                        nodeQue.push(nodeQue.front()->left);
                        level.push_back(nodeQue.front()->left->val);
                    }
                    if(nodeQue.front()->right!=0){
                        nodeQue.push(nodeQue.front()->right);
                        level.push_back(nodeQue.front()->right->val);
                    }

                    nodeQue.pop();
                }
            
                // ans.push_back(level);
                // nodeQue.pop();
                // currLevel++;
                
                ans.push_back(level);
                currLevel++;
            }
            // ans.push_back(level);
            // currLevel++;
        }
        
        return ans;
    }
};