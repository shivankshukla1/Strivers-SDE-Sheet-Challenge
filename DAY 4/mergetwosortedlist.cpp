Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* answer = new Node<int>(-1);
    Node<int>* pointer = answer;
    while(first && second){
        if(first->data < second->data){
            pointer->next = first;
            first = first->next;
        }else{
            pointer->next = second;
            second = second->next;
        }
        pointer = pointer->next;
    }
    if(first){
        pointer->next = first;
    }
    if(second){
        pointer->next = second;
    }
    return answer->next;
}
