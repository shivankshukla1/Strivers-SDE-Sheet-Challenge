#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void func(BinaryTreeNode<int>* node, vector<int>& inorder){
    if(!node){
        return;
    }
    func(node->left, inorder);
    inorder.push_back(node->data);
    func(node->right, inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    func(root, inorder);
    int l = 0, r = inorder.size() - 1;
    while(l < r){
        if(inorder[l] + inorder[r] == k){
            return 1;
        }else if(inorder[l] + inorder[r] > k){
            r -= 1;
        }else{
            l += 1;
        }
        
    }
    return 0;
}