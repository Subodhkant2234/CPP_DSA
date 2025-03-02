// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        queue<Node*>q;
        if(root == NULL) return 0;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node *Curr = q.front();
                if(Curr->left == NULL && Curr->right == NULL)
                    count++;
                q.pop();
                if(Curr->left != NULL)
                    q.push(Curr->left);
                if(Curr->right != NULL)
                    q.push(Curr->right);
            }
        }
        return count;
    }
};
