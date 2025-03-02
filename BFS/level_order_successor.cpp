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
  TreeNode *findSuccessor(TreeNode *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      TreeNode *currentNode = queue.front();
      queue.pop();
      // insert the children of current node in the queue
      if (currentNode->left != nullptr) {
        queue.push(currentNode->left);
      }
      if (currentNode->right != nullptr) {
        queue.push(currentNode->right);
      }

      // break if we have found the key
      if (currentNode->val == key) {
        break;
      }
    }

    return queue.front();
  }
};
