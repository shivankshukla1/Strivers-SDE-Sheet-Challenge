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

int func(TreeNode<int>* root, int& answer){
    if(!root){
        return 0;
    }
    int l = func(root->left, answer);
    int r = func(root->right, answer);

    answer = max(answer, l + r);

    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int answer = 0;
    func(root, answer);
    return answer;
}
