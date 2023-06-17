/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool func(BinaryTreeNode<int> *f, BinaryTreeNode<int> *s) {
    if(!f || !s){
        return f == s;
    }
    return (f->data == s->data)&&func(f->left, s->right)&&func(f->right, s->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root){
        return true;
    }  
    return func(root->left, root->right);
}