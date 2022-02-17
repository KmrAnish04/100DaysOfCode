/*
    Problem: Vertical Order Traversal Of Binary Tree
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
        LeetCode: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

    *** Algorithm (By GFG) ***
        1. Do a level order traversal and keep track of distance of node. For every left move we add -1 to the current 
        distance and for every right move we add+1 to the distance. Keep in mind that you do the mentioned things while
        level order traversal. Finally print all the nodes from lowest distance to highest.

    *** Complexity Analysis ***
        Expected Time Complexity: O(N)
        Expected Auxiliary Space: O(N)
*/




// *** GFG Solution ***
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,vector<int>> treeMap;
        queue<pair<Node*,int>> nodeQue;
        
        nodeQue.push({root, 0});
        while(!nodeQue.empty()){
            
            pair<Node*,int> front = nodeQue.front();
            treeMap[front.second].push_back(front.first->data);
            
            if(front.first->left != NULL)
                nodeQue.push({front.first->left, front.second-1});
            
            if(front.first->right != NULL)
                nodeQue.push({front.first->right, front.second+1});
            
            nodeQue.pop();
        }
        
        
        
        auto iter=treeMap.begin();
        while(iter!=treeMap.end()){
            vector<int> nodes=iter->second;
            for(int i=0; i<nodes.size(); i++){
                ans.push_back(nodes[i]);
            }
            iter++;
        }
        return ans;
    }
};



// *** LeetCode Solution ***
// comming soon .... 