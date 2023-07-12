#include<bits/stdc++.h>

class Node{
    public:
    int key;
    int val;
    Node* next = NULL;
    Node* prev = NULL;
    Node(int k, int v){
        key = k;
        val = v;
    }
};
class LRUCache {
public:
    Node* head, *tail;
    unordered_map<int, Node*> m;
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(1, 1);
        tail = new Node(1, 1);
        head->next = tail;
        tail->next = head;
    }
    
    void remove(Node* node){
        Node* prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void adding(int key, int val){
        Node* now = new Node(key, val);
        Node* next = head->next;
        head->next = now;
        now->next = next;
        next->prev = now;
        now->prev = head;
    }

    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }else{
            int val = m[key]->val;

            remove(m[key]);
            adding(key, val);
            m[key] = head->next;

            return val;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            remove(m[key]);
            adding(key, value);
            m[key] = head->next;
        }else if(size){
            size -= 1;
            adding(key, value);
            m[key] = head->next;
        }else{
            auto last = tail->prev;
            m.erase(last->key);
            remove(last);
            adding(key, value);
            m[key] = head->next;
        }
    }
};
