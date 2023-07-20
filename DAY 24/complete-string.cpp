#include <bits/stdc++.h> 
struct Node{
    Node* list[26];
    bool flag = false;
    Node(){
        for(int i = 0; i < 26; i++){
            list[i] = NULL;
        }
    }
    Node* getNext(char c){
        return list[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }
    void setNext(char c, Node* node){
        list[c - 'a'] = node;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string& s){
        Node* curr = root;
        for(int i = 0; i < s.size(); i ++){
            Node* next = curr->getNext(s[i]);
            if(next == NULL){
                curr->setNext(s[i], new Node());
            }
            next = curr->getNext(s[i]);
            curr = next;
        }
        curr->setEnd();
    }

    bool check(string& s){
        Node* curr = root;
        for(int i =0 ; i < s.size(); i++){
            Node* next = curr->getNext(s[i]);
            curr = next;
            if(!curr->getEnd()){
                return false;
            }
        }
        return true;
    }
};


string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto i : a){
        trie.insert(i);
    }
    string answer = "";
    for(auto i : a){
        // cout<<i<<endl;
        int flag = trie.check(i);
        if(flag){
            if((answer.size() < i.size() )|| (answer.size() == i.size() && answer > i)) {
                answer = i;
            }
        }
    }

    if(answer.size() == 0){
        return "None";
    }
    return answer;
}