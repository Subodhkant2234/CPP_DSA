void printKDist(Node *root,int k){
    if(root==NULL)return;
    
    if(k==0)
    {
      cout<<root->key<<" ";
    }
    else
    {
    printKDist(root->left,k-1);
    printKDist(root->right,k-1);
    }
}  
