#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

void func(TreeNode<int>* root, int x, vector<int>& curr, vector<int>& answer){
	if(!root){
		return;
	}
	
	curr.push_back(root->data);
	if(root->data == x){
		answer = curr;
		return;
	}
	func(root->left, x, curr, answer);
	func(root->right, x, curr, answer);
	curr.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> curr;
	vector<int> answer;
	func(root, x, curr, answer);
	return answer;
}
