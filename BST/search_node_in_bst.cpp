// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root == NULL)
        return false;
    while(root != NULL){
        if(root->data == x)
            return true;
        else if(root->data > x)
            root = root->left;
        else 
            root = root->right;
    }
    return false;
}
