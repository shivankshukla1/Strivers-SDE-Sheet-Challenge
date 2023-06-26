/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* func(int post_s, int post_e, int in_s, int in_e, vector<int>&postOrder, vector<int>& inOrder, unordered_map<int, int> m){
     if(post_s > post_e || in_s > in_e){
          return NULL;
     }
     TreeNode<int>* now = new TreeNode<int>(postOrder[post_e]);
     int ind = m[postOrder[post_e]];
     int len = ind - in_s;
     now->left = func(post_s, post_s + len - 1, in_s, ind - 1, postOrder, inOrder, m);
     now->right = func(post_s + len, post_e - 1, ind + 1, in_e, postOrder, inOrder, m);

     return now; 
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     unordered_map<int, int> m;
     for(int i = 0; i < inOrder.size(); i ++){
          m[inOrder[i]] = i;
     }
     int n = postOrder.size();
     return func(0, n - 1, 0, n - 1, postOrder, inOrder, m);
}
