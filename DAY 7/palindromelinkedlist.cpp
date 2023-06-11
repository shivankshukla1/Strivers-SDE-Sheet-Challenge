#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int>* newhead = NULL;
    while(head){
        LinkedListNode<int>* next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
    return newhead;
}

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int>* fast = head, *slow = head;
    if(!head || !head->next){
        return 1;
    }
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while(slow){
        if(slow->data != head->data){
            return 0;
        }
        slow = slow->next;
        head = head->next;
    }
    return 1;
}