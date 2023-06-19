#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void func(TreeNode* root, vector<int>& answer){
    if(!root){
        return;
    }
    answer.push_back(root->data);
    func(root->left, answer);
    func(root->right, answer);
}


vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> answer;
    func(root, answer);

    return answer;
}