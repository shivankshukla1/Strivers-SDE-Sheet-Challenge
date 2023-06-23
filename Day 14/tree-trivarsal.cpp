#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> ino, pre, post;
    if(!root){
        return {};
    }
     stack<pair<int, BinaryTreeNode<int>*>> q;
     q.push({1, root});

    while(q.size()){
        BinaryTreeNode<int>* node = q.top().second;
        int now = q.top().first;
        q.pop();
        
        if(now == 1){
            ino.push_back(node->data);
            q.push({now + 1, node});
            if(node->left){
                q.push({1, node->left});
            }
        }else if(now == 2){
            q.push({now + 1, node});
            pre.push_back(node->data);    
            if(node->right){
                q.push({1, node->right});
            }
        }else{
           post.push_back(node->data);
        }
    }
    return {pre, ino, post};
}