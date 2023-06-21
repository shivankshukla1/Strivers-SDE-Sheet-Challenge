#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// int count;
long long func(TreeNode<int>* root, long long& answer, int & count){
    if(!root){
        return 0ll;
    }
    if(!root->left && !root->right){
        count += 1;
    }
    long long left = func(root->left, answer, count);
    long long right = func(root->right, answer, count);
   
    answer = max(answer, left + right + root->val);

    return max(left, right) + root->val; 
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    int count = 0;
    long long answer = 0;
    func(root, answer, count);
    if(count < 2){
        return -1;
    }
    return answer;
}