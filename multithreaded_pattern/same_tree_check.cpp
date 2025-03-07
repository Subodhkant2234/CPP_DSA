class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // p and q are both nullptr
        if (!p && !q) return true;
        // one of p and q is nullptr
        if (!p || !q) return false;
        // one of p and q has a different value
        if (p->val != q->val) return false;

        // check left and right subtree recursively
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};
