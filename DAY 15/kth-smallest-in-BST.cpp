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
    };

************************************************************/

void func(TreeNode<int>* root, int &k, int &answer){
    if(!root){
        return;
    }
    func(root->left, k, answer);
    // cout<<"root is "<<root->data<<" adn "<<k<<endl;
    k -= 1;
    if(k == 0){
        answer = root->data;
    }

    func(root->right, k, answer);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int answer = -1;
    func(root, k, answer);
    return answer;
}