Node *firstNode(Node *head)
{
    Node* slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    retu