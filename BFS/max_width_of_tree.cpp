class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        // Your code here
        if(root == NULL)
            return 0;
        queue<Node*>q;
        q.push(root);
        int res = 0;
        int size = 0;
        
        while(!q.empty()){
            size = q.size();
            res = max(size, res);
            for(int i = 0; i < size; i++){
                Node *curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return res;
    }
};
