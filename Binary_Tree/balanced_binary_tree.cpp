class Solution {
public:
    int get_height_imbalance(TreeNode* root) {
        if (root == NULL)
            return true;

        int lh = get_height_imbalance(root->left);
        if (lh == -1)
            return -1;
        int rh = get_height_imbalance(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) 
    { 
        return get_height_imbalance(root) != -1; 
    }
};
