/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    int len = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        len += 1;
    }
    k = len - k;
    if(k == 0){
        return head->next;
    }
    k -= 1;

    Node* fast = head;

    while(k--){
        fast = fast->next;
    }
    fast->next = fast->next->next;
    
    return head;
}
