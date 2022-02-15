/*
    Problem Link: Left view of a Binary Tree
    Question Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

    *** Complexity Analysis ***
        Expected Time Complexity: O(N).
        Expected Auxiliary Space: O(Height of the Tree).
*/


/* A binary tree node

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

/* ********************************** Recursive Solution ********************************** */

// The below was my approch, 90% is correct but still something is wrong in my approch maybe something is wrong with the "desiredLevel" variable, i have to figure it out.
int desiredLevel=0;
void finder(Node *root, vector<int> &ans, int currLevel){
    
    // if(root==NULL) return;
    if(desiredLevel==currLevel){
        // cout<<"ans.size(): "<<ans.size()<<endl;
        // cout<<"desLev: "<<desiredLevel<<endl;
        ans.push_back(root->data);
        desiredLevel++;
    }

    finder(root->left, ans, currLevel+1);
    finder(root->right, ans, currLevel+1);
}


// The below is the correct and working solution
void finder(Node *root, vector<int> &ans, int currLevel){
    
    if(root==NULL) return;
    if(ans.size()==currLevel){
        cout<<"ans.size(): "<<ans.size()<<endl;
        cout<<"ans.size: "<<ans.size()<<endl;
        ans.push_back(root->data);
        desiredLevel++;
    }
    finder(root->left, ans, currLevel+1);
    finder(root->right, ans, currLevel+1);
}


//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   int currLev=0;
   finder(root, ans, currLev); 
   return ans;
}
