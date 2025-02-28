using namespace std;

#include <iostream>
#include <queue>

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
  int findDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    int minimumTreeDepth = 0;
    while (!queue.empty()) {
      minimumTreeDepth++;
      int levelSize = queue.size();
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();

        // check if this is a leaf node
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
          return minimumTreeDepth;
        }

        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
    }
    return minimumTreeDepth;
  }
};

