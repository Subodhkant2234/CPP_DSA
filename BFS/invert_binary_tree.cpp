// Convert Mirror tree(Change to Mirror Tree) i.e invert binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL)
            return root;
        q.push(root);
        while (!q.empty()) {
            TreeNode* Curr = q.front();
            q.pop();
            swap(Curr->left, Curr->right);
            if (Curr->left != NULL)
                q.push(Curr->left);
            if (Curr->right != NULL)
                q.push(Curr->right);
        }
        return root;
    }
};
