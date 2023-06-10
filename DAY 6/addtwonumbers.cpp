Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* answer = new Node(-1), *pointer = answer;
    int carry = 0;
    while(num1 || num2 || carry){
        int sum = carry;
        int f = 0;
        if(num1){
            sum += num1->data;
            num1 = num1->next;
            f = 1;
        }
        if(num2){
            sum += num2->data;
            num2 = num2->next;
            f = 1;
        }
        carry = sum/10;
        sum %= 10;
        Node* next = new Node(sum);
        pointer->next = next;
        pointer = pointer->next;
    }

    return answer->next;
}
