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

vector<int> getLeftView(TreeNode<int> *root)
{
    map<int, int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    if(!root){
        return {};
    }
    while(q.size()){
        auto node = q.front().first;
        int x = q.front().second;
        q.pop();

        if(m.find(x) == m.end()){
            m[x] = node->data;
        }
        if(node->left){
            q.push({node->left, x + 1});
        }
        if(node->right){
            q.push({node->right, x + 1});
        }
    }
    vector<int> answer;

    for(auto i : m){
        answer.push_back(i.second);
    }

    return answer;
}