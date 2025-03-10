int minValue(struct Node *root) {

    // If the root is NULL, return -1 indicating that the tree is empty
    if (root == NULL) {
        return -1;
    }

    // Initialize the answer with the value of the root node
    int ans = root->data;

    // Traverse to the leftmost node of the tree
    while (root != NULL) {

        // Update the answer with the value of the current node
        ans = root->data;

        // Move to the left child of the current node
        root = root->left;
    }

    // Return the minimum value found in the tree
    return ans;
}
