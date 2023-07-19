/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node{
    public:
    Node* list[26];
    bool flag;
    Node(){
        flag = false;
    }
    void setFlag(){
        flag = true;
    }
    bool getFlag(){
        return flag;
    }
    Node* getNext(char c){
        return list[c - 'a'];
    }
    void setNext(char c, Node* node){
        list[c-'a'] = node;
    }

};
class Trie {

public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getNext(i);
            if(!next){
                curr->setNext(i, new Node());
                next = curr->getNext(i);
            }
            curr = next;
        }
        curr->setFlag();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getNext(i);
            if(!next){
                return false;
            }
            curr = next;
        }
        return curr->getFlag();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* curr = root;
        for(auto i : word){
            Node* next = curr->getNext(i);
            if(!next){
                return false;
            }
            curr = next;
        }
        return true;
    }
};