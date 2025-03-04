using namespace std;

#include <iostream>

// class TreeNode {
// public:
//   int val = 0;
//   TreeNode *left;
//   TreeNode *right;

//   TreeNode(int x) {
//     val = x;
//     left = right = nullptr;
//   }
// };

class Solution {
public:
  bool hasPath(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }

    // if the current node is leaf and its value is equal to the sum, we've found a path
    if (root->val == sum && root->left == nullptr && root->right == nullptr) {
      return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
  }
};
