class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if(root == NULL)
            return INT_MIN;
        return max(root->data, max(findMax(root->left), findMax(root->right)));
    }
    int findMin(Node *root)
    {
        //code here
        if(root == NULL)
            return INT_MAX;
        return min(root->data, min(findMin(root->left),findMin(root->right)));
    }
};

/*
Int findMax(Node root)
{
	if(root==null)
		Return Integer.MIN_VALUE;
	Int res=root.data
	Int lres= findMax(root.left);
	Int rres= findMax(root.right);
	if(res<lres)
		res=lres;
	if(res<rres)
		res=rres;
	Return res;
}
*/
