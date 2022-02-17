/*
    Problem: Bottom view of Binary Tree
    Question Link:  
        GFG: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
        LeetCode: **Not Available

    ***Algorithm: 
        Method 1 – Using Queue:
        The following are steps to print Bottom View of Binary Tree.
        1. We put tree nodes in a queue for the level order traversal.
        2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1.
        3. Also, use a TreeMap which stores key value pair sorted on key.
        4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal distance as key. For the first time it will add to the map, next time it will replace the value. This will make sure that the bottom most element for that horizontal distance is present in the map and if you see the tree from beneath that you will see that element.


        OR

        Method 2 (Using HashMap):
        Create a map like, map where key is the horizontal distance and value is a pair(a, b) where a is the value of the node and b is the height of the node. 
        Perform a pre-order traversal of the tree. If the current node at a horizontal distance of h is the first we’ve seen, insert it in the map. Otherwise, compare the 
        node with the existing one in map and if the height of the new node is greater, update in the Map.


        *** Complexity Analysis ***
            Time: O(N)
            Space: O(N)
*/



// GFG Solution
// Method 2 Solution
class Solution {
  public:
    void preOrd(Node *root, map<int,pair<int,int>> &treeMap, int hD, int vL){
        if(root==NULL) return;
        
        if(treeMap.find(hD)==treeMap.end()){
            treeMap[hD]={root->data, vL};
        }
        else{
            if(treeMap[hD].second<=vL){
                treeMap[hD]={root->data, vL};
            }
        }
        
        preOrd(root->left, treeMap, hD-1, vL+1);
        preOrd(root->right, treeMap, hD+1, vL+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,pair<int,int>> treeMap;
        
        preOrd(root, treeMap, 0, 0);
        
        auto iter=treeMap.begin();
        while(iter!=treeMap.end()){
            ans.push_back(iter->second.first);
            iter++;
        }
        
        return ans;
    }
};





