#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, vector<int> &inVal)
{
    if(root == NULL)
    return;
    inorder(root->left,inVal);
    inVal.push_back(root->data);
    inorder(root->right,inVal);
    
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // storing the sorted inorder data in a
    if (root == NULL)
        return NULL;

    vector<int> inVal;
    inorder(root,inVal);
    int n = inVal.size();
    // now making a new root node to store the first element
    TreeNode<int>* newroot = new TreeNode<int>(inVal[0]);
    // another node which will store the current location
    TreeNode<int>* current = newroot;

    // step 2
    for(int i = 1; i <n;i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inVal[i]);
        current->left = NULL;
        current->right = temp;
        current = temp;
    }
return newroot;

}
