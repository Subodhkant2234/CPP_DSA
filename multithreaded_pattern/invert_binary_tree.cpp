class Solution {
public:
    // Function to invert a binary tree
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the root is null, return null
        if (root == NULL) {
            return NULL;
        }

        // Swap the left and right children of the current node
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
