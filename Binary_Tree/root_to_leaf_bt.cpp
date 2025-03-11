class Solution {
  public:
    void PathsHelper(Node* currentNode, vector<int> &currentpath, vector<vector<int>> &allpaths){
        if(currentNode == NULL)
            return;
        currentpath.push_back(currentNode->data);
        if(currentNode->left == NULL && currentNode->right == NULL) {
            allpaths.push_back(currentpath);
        }
        else {
            PathsHelper(currentNode->left, currentpath, allpaths);
            PathsHelper(currentNode->right, currentpath, allpaths);
        }
        currentpath.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>currentpath;
        vector<vector<int>> allpaths;
        PathsHelper(root, currentpath, allpaths);
        return allpaths;
    }
};
