//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};


// } Driver Code Ends

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

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> res;
        queue<Node *> q;
        
        if(root == NULL)
            return res;
        
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            Node *CurrentNode = NULL;
            for(int i = 0; i < level; i++){
                CurrentNode = q.front();
                q.pop();
                if(i == 0)
                    res.push_back(CurrentNode->data);
                if(CurrentNode->left != NULL)
                    q.push(CurrentNode->left);
                if(CurrentNode->right != NULL)
                    q.push(CurrentNode->right);
            }
        }
        return res;
    }
};

