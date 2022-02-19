/*
    Problem: Connect Nodes at same level/ Populating Next Right Pointers in Each Node
    Question Link:
        GFG:
        Leetcode:
        Both the questions are not exactly same, Like in GFG the tree is a BST but in Leetcode the tree is
        not BST, so the both question can be solved with different approches also but I have used a common
        approch which works for Leetcode and also works for GFG.

    Complexity Analysis:
        Expected Time Complexity: O(N)
        Expected Auxiliary Space: O(N)

*/


// GFG Solution
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

class Solution
{
public:
    // Function to connect nodes at same level.
    void connect(Node *root)
    {
        // Your Code Here
        if (root == NULL)
            return;
        deque<Node *> que;
        //   vector<Node*> vec1
        que.push_back(root);
        //   vec1.push_back(root);

        while (!que.empty())
        {

            vector<Node *> vec;
            for (int i = 0; i < que.size(); i++)
            {
                vec.push_back(que[i]);
            }

            int size = que.size();
            int idx = 1;
            for (int i = 0; i < size; i++)
            {
                Node *front = que.front();
                if (idx < vec.size())
                {
                    front->nextRight = vec[idx];
                    idx++;
                }
                else
                    front->nextRight = NULL;

                if (front->left != NULL)
                    que.push_back(front->left);
                if (front->right != NULL)
                    que.push_back(front->right);

                que.pop_front();
            }
        }
    }
};

// Leetcode Solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // Your Code Here
        if (root == NULL)
            return root;
        deque<Node *> que;
        //   vector<Node*> vec1
        que.push_back(root);
        //   vec1.push_back(root);

        while (!que.empty())
        {

            vector<Node *> vec;
            for (int i = 0; i < que.size(); i++)
            {
                vec.push_back(que[i]);
            }

            int size = que.size();
            int idx = 1;
            for (int i = 0; i < size; i++)
            {
                Node *front = que.front();
                if (idx < vec.size())
                {
                    front->next = vec[idx];
                    idx++;
                }
                else
                    front->next = NULL;

                if (front->left != NULL)
                    que.push_back(front->left);
                if (front->right != NULL)
                    que.push_back(front->right);

                que.pop_front();
            }
        }
        return root;
    }
};