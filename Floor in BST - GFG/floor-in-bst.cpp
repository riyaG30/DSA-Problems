//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends




 //<<<<<<<<<<<<<<<<<<<------------------------------BRUTTE FORCE APPROACH--------------------------------->>>>>>>>>>
// void inorder(TreeNode<int> * root, vector<int> &v)
// {
//     if(root == NULL) return ;
//     inorder(root->left, v);
//     v.push_back(root->val);
//     inorder(root->right, v);
// }
// int floorInBST(TreeNode<int> * root, int x)
// {
//     // Write your code here.
//     if(root == NULL)
//     return -1;
//     vector<int> v;
//     int ans = -1;
//     inorder(root,v);
//     int size = v.size();
//     for(int i = size-1; i >= 0; i--)
//     {
//         if(v[i] <= x)
//         {
//             ans = v[i];
//             return ans;
//         }
       
        
//     }
    
//       return -1;
// }
// <<<<<<<<<<<<<<<<<<<<<<<<<<<--------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int floor(Node* root, int x) {
    int floor = -1;
    if(root == NULL)
    return -1;
    while(root)
    {
        if(root->data == x)
        {
            floor = root->data;
        return floor;
        }
        
        if(x > root->data)
        {
            floor = root->data;
             root = root->right;
        }
        else
        root = root->left;
       
    }
    return floor;
}
