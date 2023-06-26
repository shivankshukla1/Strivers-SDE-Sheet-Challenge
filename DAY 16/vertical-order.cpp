#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> answer;

    map<int, map<int, vector<int>>> level;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    if(!root){
        return answer;
    }

    while(q.size()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        TreeNode<int>* node = q.front().first;
        q.pop();

        level[y][x].push_back(node->data);
        if(node->left){
            q.push({node->left, {x + 1, y - 1}});
        }
        if(node->right){
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    for(auto i : level){
        for(auto j : i.second){
            for(auto k : j.second){
                answer.push_back(k);
            }
        }
    }


    return answer;
}