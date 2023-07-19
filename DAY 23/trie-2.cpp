#include <bits/stdc++.h> 
class Node{
    public:
    Node* list[26];
    int wordEnds;
    int prefix;
    Node(){
        wordEnds = 0;
        prefix = 0;
    }
    Node* getnext(char c){
        return list[c - 'a'];
    }
    void setnext(char c, Node* node){
        list[c-'a'] = node;
    }
    int countEnd(){
        return wordEnds;
    }
    void addEnd(){
        wordEnds += 1;
    }
    void addPrefix(){
        prefix += 1;
    }
    int countPrefix(){
        return prefix;
    }
    void removeEnd(){
        wordEnds -= 1;
    }
    void removePrefix(){
        prefix -= 1;
    }

};

class Trie{

    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getnext(i);
            if(next == NULL){
                curr->setnext(i, new Node());
            }
            next = curr->getnext(i);
            curr->addPrefix();
            curr = next;
        }
        curr->addPrefix();
        curr->addEnd();
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getnext(i);
            if(next == NULL){
                return 0;
            }
            curr = next;
        }
        return curr->countEnd();
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getnext(i);
            if(next == NULL){
                return 0;
            }
            curr = next;
        }
        return curr->countPrefix();
    }

    void erase(string &word){
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getnext(i);
            if(next == NULL){
                return;
            }
            curr->removePrefix();
            curr = next;
        }
        curr->removePrefix();
        curr->removeEnd();
    }
};
