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

string serializeTree(TreeNode<int> *root)
{
    if(!root){
        return "";
    }
    string answer = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()){
        TreeNode<int>* node = q.front();
        q.pop();
        if(!node){
            answer += to_string(0);
        }else{
            answer += to_string(node->data);
            q.push(node->left);
            q.push(node->right);
        }
        answer += ",";
    }
    return answer;

}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size() == 0){
        return NULL;
    }
    vector<int> nodes;
    int curr = 0;
    for(auto i : serialized){
        if(i == ','){
            nodes.push_back(curr);
            curr = 0;
        }else{
            curr *= 10;
            curr += (i - '0');
        }
    }
    queue<TreeNode<int>*> q;
    TreeNode<int>* node = new TreeNode<int>(nodes[0]);
    TreeNode<int>*pointer = node;

    q.push(node);
    int ind = 1;
    while(q.size()){
        TreeNode<int>* curr = q.front();
        q.pop();
        if(nodes[ind] == 0){
            curr->left = NULL;
        }else{
            curr->left = new TreeNode<int>(nodes[ind]);
            q.push(curr->left);
        }
        ind += 1;

        if(nodes[ind] == 0){
            curr->right = NULL;
        }else{
            curr->right = new TreeNode<int>(nodes[ind]);
            q.push(curr->right);
        }
        ind += 1;
    }

    return pointer;
}



