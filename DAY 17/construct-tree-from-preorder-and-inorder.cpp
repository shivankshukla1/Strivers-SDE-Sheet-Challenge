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
    };a

************************************************************/

TreeNode<int>* func(int in_s, int in_e, int pre_s, int pre_e, vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& m){
    if(in_s > in_e || pre_s > pre_e){
        return NULL;
    }
    TreeNode<int>* now = new TreeNode<int>(preorder[pre_s]);

    int ind = m[preorder[pre_s]];
    int len = ind - in_s;


    now->left = func(in_s, ind - 1, pre_s + 1, pre_s + len, inorder, preorder, m);
    now->right = func(ind + 1, in_e, pre_s+len+1, pre_e, inorder, preorder, m);

    return now;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    unordered_map<int, int> m;
    for(int i = 0; i < n; i ++){
        m[inorder[i]] = i;
    }
    return func(0, n - 1, 0, n - 1, inorder, preorder, m);
}