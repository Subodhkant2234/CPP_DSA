class Solution {

public:
    bool is_within_bounds(TreeNode* root, long min, long max) {
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return (is_within_bounds(root->left, min, root->val) &&
                is_within_bounds(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        return is_within_bounds(root, LONG_MIN, LONG_MAX);
    }
};
