#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> answer;
    if(!root){
        return answer;
    }
    map<int, int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    m[0] = root->val;

    while(q.size()){
        int size = q.size();
        while(size--){
            auto node = q.front().first;
            int x = q.front().second;
            q.pop();

            if(m.find(x) == m.end()){
                m[x] = node->val;
            }

            if(node->left){
                q.push({node->left, x - 1});
            }
            if(node->right){
                q.push({node->right, x + 1});
            }
        }
    }

    for(auto i : m){
        answer.push_back(i.second);
    }
    return answer;
}