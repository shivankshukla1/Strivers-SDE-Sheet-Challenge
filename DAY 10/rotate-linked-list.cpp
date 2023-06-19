/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     int len = 1;
     Node* temp = head;
     while(head->next){
          head = head->next;
          len += 1;
     }
     head->next = temp;
     k %= len;
     k = len - k;
     while(k--){
          head = head->next;
     }
     temp = head->next;
     head->next = NULL;
     return temp;    
}