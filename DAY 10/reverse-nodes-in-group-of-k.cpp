#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(!head){
		return head;
	}
	int len = 0;
	Node* temp = head;
	while(temp){
		len += 1;
		temp = temp->next;
	}
	Node* pre = new Node(-1);
	Node* answer = pre;
	pre->next = head;
	
	
	for(int j = 0; j < n; j ++){
		if(b[j] == 0){
			continue;
		}
		// cout<<b[j]<<" this is the element"<<endl;
		if(len <= b[j]){
			// cout<<"here1"<<endl;
			Node* newhead = NULL;	
			for(int i = 0; i < min(len, b[j]); i++){
				// cout<<"node is "<<head->data<<endl;
				Node* next = head->next;
				head->next = newhead;
				newhead = head;
				head = next;
			}
			Node* curr = pre->next;
			pre->next= newhead;
			curr->next = head;
			pre = curr;
			break;
		}else{
			// cout<<"here2"<<endl;
			Node* newhead = NULL;	
			for(int i = 0; i < min(len, b[j]); i++){
				// cout<<"node is "<<head->data<<endl;
				Node* next = head->next;
				head->next = newhead;
				newhead = head;
				head = next;
			}
			Node* curr = pre->next;
			pre->next= newhead;
			curr->next = head;
			pre = curr;


			
			
			len -= b[j];
		}
	}	
	return answer->next;
}