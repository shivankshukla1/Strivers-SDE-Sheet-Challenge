#include <bits/stdc++.h> 
class Node {

public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


class Queue {
private:
    Node* qfront;
    Node* rear;
public:
    Queue() {
        qfront = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        if(qfront == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        Node* newnode = new Node(data);
        if (isEmpty()) {
            qfront = newnode;
            rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

 

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int ans = qfront->data;
        Node* temp = qfront;
        qfront = qfront->next;
        if (qfront == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return ans;
    }
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return qfront->data;
    }
};