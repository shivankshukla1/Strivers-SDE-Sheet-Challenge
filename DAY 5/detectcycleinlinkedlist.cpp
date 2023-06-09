bool detectCycle(Node *head)
{
    Node* f= head, *s = head;
    while(f && f->next){
        f = f->next->next;
        s = s->next;
        if(f == s){
            return 1;
        }
    }
    return 0;
}