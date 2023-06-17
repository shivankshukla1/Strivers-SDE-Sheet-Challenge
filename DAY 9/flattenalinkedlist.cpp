/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* f, Node* s){
	Node* answer = new Node(-1), *shiv = answer;

	while(f && s){
		if(f->data < s->data){
			answer->child = f;
			f = f->child;
		}else{
			answer->child = s;
			s = s->child;
		}
		answer = answer->child;
	}
	while(f){
		answer->child = f;
		f = f->child;
		answer = answer->child;
	
	}
	while(s){
		answer->child = s;
		s = s->child;
		answer = answer->child;
	}
	return shiv->child;
}

Node* flattenLinkedList(Node* head) 
{
	Node* answer = new Node(-1);

	while(head){
		Node* next = head->next;
		head->next = NULL;
		answer = merge(answer, head);
		head = next;
	}

	return answer->child;
}
