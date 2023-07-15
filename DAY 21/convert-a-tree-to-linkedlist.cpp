#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>* answer = root;
    while(root){
        if(root->left){
            TreeNode<int>* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }

    return answer;
}