/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root, vector<int> &inVal)
{
    if(root == NULL)
    return;
    inorder(root->left,inVal);
    inVal.push_back(root->data);
    inorder(root->right,inVal);
    
}
TreeNode<int>* inorderToBst(int s, int e, vector<int> v)
{
    if(s>e)
    return NULL;
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(v[mid]);
    root->left  = inorderToBst(s,  mid-1,  v);
     root->right  = inorderToBst(mid+1,  e,  v);
     return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {

    if (root == NULL)
        return NULL;

    vector<int> inVal;
    // store inorder -> sorted values
    inorder(root,inVal);
    int n = inVal.size();
    return inorderToBst(0, n-1,  inVal);

}
