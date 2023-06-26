#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*> q;
    if(!root){
        return;
    }
    q.push(root);

    while(q.size()){
        int size = q.size();
        BinaryTreeNode<int>* pre = NULL;
        while(size--){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(pre){
                // cout<<pre->data<<" And "<<node->data<<endl;
                
                pre->next = node;
            }
            pre = node;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }   
}