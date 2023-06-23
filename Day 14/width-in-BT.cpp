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

int getMaxWidth(TreeNode<int> *root)
{   if(!root){
        return 0;
    }
    queue<pair<int, TreeNode<int>*>> q;
    q.push({1, root});
    int answer = 0;

    while(q.size()){
        int first, last;
        int curr = q.front().first;
        int size = q.size();
        answer = max(answer, size);
        for(int i = 0; i < size; i ++){
            int val = q.front().first;
            TreeNode<int>* node = q.front().second;
            q.pop();
            if(i == 0){
                first = val;
            }
            if(i == size-1){
                last = val;
            }
            val -= curr;
            if(node->left){
                q.push({2*val, node->left});
            }
            if(node->right){
                q.push({2*val + 1, node->right});
            }
        }
    }





    return answer;
}