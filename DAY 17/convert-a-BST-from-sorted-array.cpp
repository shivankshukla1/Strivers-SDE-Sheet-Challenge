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

TreeNode<int>* func(int l, int r, vector<int>& arr){
    if(l > r){
        return NULL;
    }
    int mid = (l+r)/2;
    TreeNode<int>* now = new TreeNode<int>(arr[mid]);
    now->left = func(l, mid - 1, arr);
    now->right = func(mid + 1, r, arr);
    return now;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return func(0, n - 1, arr);
}