#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* func(int l, int r,vector<int>& preOrder){
    
    if(l > r){
        return NULL;
    }
    TreeNode<int>* node = new TreeNode<int>(preOrder[l]);
    int ind = l;
    for(int i = l + 1; i <= r; i++){
        if(preOrder[i] < preOrder[l]){
            ind = i;
        }else{
            break;
        }
    }

    node->left = func(l + 1, ind, preOrder);
    node->right = func(ind + 1, r, preOrder);
    return node;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    return func(0, preOrder.size() - 1, preOrder);
}