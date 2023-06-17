#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

int succ(BinaryTreeNode<int>* root, int key){
    int answer = -1;
    while(root){
        if(root->data <= key){
            root = root->right;
        }else{
            answer = root->data;
            root = root->left;
        }
    }
    return answer;
}

int pre(BinaryTreeNode<int>* root, int key){
    int answer = -1;
    while(root){
        if(root->data < key){
            answer = root->data;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return answer;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    return {pre(root, key), succ(root, key)};
}
