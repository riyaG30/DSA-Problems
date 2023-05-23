pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1;
    int suc = -1;
    // find key
    if( root == NULL)
      return {0, 0};
     BinaryTreeNode<int> * temp = root;
    while(temp->data != key)
    {
        if(temp->data > key)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }
    // now finding predecessor
    BinaryTreeNode<int>* leftSubTree = temp->left;
    while(leftSubTree != NULL)
    {
         pre = leftSubTree->data;
        leftSubTree = leftSubTree->right; // finding maximum of left subtree
   
    }
   
    // now finding successor
    BinaryTreeNode<int>* rightSubTree = temp->right;
    while(rightSubTree != NULL)
    {
       suc = rightSubTree->data;
        rightSubTree = rightSubTree->left; // finding minimum of left subtree
       
    }
     
    return {pre,suc};
}
