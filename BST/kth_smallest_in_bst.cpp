class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        stack<Node*>st;
        Node *curr = root;
        while(!st.empty() || curr != NULL){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            k--;
            st.pop();
            if(k == 0) {
                return curr->data;
            }
            curr = curr->right;
        }
        return -1;
    }
};
