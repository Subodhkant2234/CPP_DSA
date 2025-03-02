class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int>res;
        int level = 0;
        queue<Node*>q;
        if(root == NULL)
            return res;
        if(k == 0) {
            res.push_back(root->data);
            return res;
        }
            
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            if(level == k){
                for(int i = 0; i < size; i++){
                    Node *tmp = q.front();
                    res.push_back(tmp->data);
                    q.pop();
                }
                return res;
            }
            
            for(int i = 0; i < size; i++){
                Node *CurrentNode = q.front();
                q.pop();
                if(CurrentNode->left != NULL)
                    q.push(CurrentNode->left);
                if(CurrentNode->right != NULL)
                    q.push(CurrentNode->right);
            }
            level++;
        }
    }
};
