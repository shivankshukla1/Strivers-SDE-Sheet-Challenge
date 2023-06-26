#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


*************************************************************/
int func(BinaryTreeNode<int>* root){
    if(!root){
        return 0;
    }
    int sum = 0;
    if(root->left){
        sum += root->left->data;
    }
    if(root->right){
        sum += root->right->data;
    }

    if(root->data >= sum){
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    func(root->right);
    func(root->left);
    if(root->right || root->left){
        sum = 0;
        if(root->left){
            sum += root->left->data;
        }
        if(root->right){
            sum += root->right->data;
        }
        root->data = sum;
    }
    return sum;
}
void changeTree(BinaryTreeNode < int > * root) {
    func(root);
}  