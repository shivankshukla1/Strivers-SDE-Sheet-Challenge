#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> answer;
    if(!root){
        return answer;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int rev = 0;
    while(q.size()){
        int size = q.size();
        vector<int> curr;
        while(size--){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            curr.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        if(rev){
            reverse(curr.begin(), curr.end());
        }
        for(auto i : curr){
            answer.push_back(i);
        }
        rev = 1 - rev;
    }

    return answer;
}
