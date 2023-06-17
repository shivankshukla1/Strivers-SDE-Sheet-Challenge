#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    stack<TreeNode<int>*> st;
    while(true){
        if(root){
            st.push(root);
            root = root->right;
        }else{
            if(st.size() == 0){
                break;
            }

            k -= 1;
            root = st.top();
            st.pop();
            // cout<<k<<" And "<<root->data<<endl;
            if(k == 0){
                return root->data;
            }
            root = root->left;
        }
    }
    return -1;
}
