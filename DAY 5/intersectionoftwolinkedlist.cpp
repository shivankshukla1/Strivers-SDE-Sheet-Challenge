Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* f = firstHead, *s = secondHead;
    while(f != s){
        if(f){
            f = f->next;
        }else{
            f = secondHead;
        }
        if(s){
            s = s->next;
        }else{
            s = firstHead;
        }
    }
    return f;
}