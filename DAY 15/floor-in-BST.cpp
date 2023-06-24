#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void func(TreeNode<int>* root, int x, int& answer){
    while(root){
        if(root->val <= x){
            answer = root->val;
            root = root->right;
        }else{
            root= root->left;
        }
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    int answer = -1;
    func(root, X, answer);
    return answer;
}