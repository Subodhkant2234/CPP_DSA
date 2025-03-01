#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
    
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<int> traverse(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* currentNode = NULL;
            for (int i = 0; i < levelSize; i++) {
                currentNode = q.front();
                q.pop();
                // insert the children of current node in the queue
                if (currentNode->left != NULL)
                    q.push(currentNode->left);
                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }
            // Add last node of the current node in the result.
            result.push_back(currentNode->val);
        }

        return result;
    }
};
