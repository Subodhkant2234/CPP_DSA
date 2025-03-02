using namespace std;

#include <deque>
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
  vector<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();
    vector<vector<int>> output = vector<vector<int>>();
    if (root == nullptr) {
      return output;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node to the current level
        currentLevel.push_back(currentNode->val);
        // insert the children of current node to the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      // append the current level at the beginning
      result.push_front(currentLevel);
    }

    // convert the result queue to vector for output
    for (auto level : result) {
      output.push_back(level);
    }

    return output;
  }
};

