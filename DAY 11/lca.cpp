#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

TreeNode<int>* func(TreeNode<int>* root, int x, int y){
        if(!root || root->data == x || root->data == y){
        return root;
    }
    TreeNode<int>* left = func(root->left, x, y);
    TreeNode<int>* right = func(root->right, x, y);
    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }

}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int>* answer =  func(root, x, y);
    if(!answer){
        return -1;
    }else{
        return answer->data;
    }
}