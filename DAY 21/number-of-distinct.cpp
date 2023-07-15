#include <bits/stdc++.h>
using namespace std;
 
class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode()
    {
        isWord = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = 0;
        }
    }
};
 

int distinctSubstring(string &str) {
    TrieNode* head = new TrieNode();
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        TrieNode* temp = head; 
        for (int j = i; j < str.length(); j++) {
            if (temp->child[str[j] - 'a'] == NULL) {
                temp->child[str[j] - 'a'] = new TrieNode();
                temp->isWord = 1;
                count++;
            }
            temp = temp->child[str[j] - 'a'];
        }
    } 
    return count;
}
