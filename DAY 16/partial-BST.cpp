#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool func(BinaryTreeNode<int>* root, int mini, int maxi){
    if(!root){
        return 1;
    }
    bool answer = 1;

    if(root->data >= mini && root->data <= maxi){
        answer &= func(root->left, mini, root->data);
        answer &= func(root->right, root->data, maxi);
    }else{
        // cout<<"hrer"<<endl;
        return 0;
    }


    return answer;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return func(root, INT_MIN, INT_MAX);
}