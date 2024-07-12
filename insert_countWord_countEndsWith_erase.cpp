

// Problem Link - https://www.naukri.com/code360/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

class Node {
    Node* links[26];
    int endsWith = 0;
    int prefix = 0;

    public: 
    bool containsKey(char ch) {
        return links[ch-'a'] != nullptr;
    }

    void put(char ch) {
        this->links[ch-'a'] = new Node();
    }

    void decreasePrefix() {
        if(prefix > 0) this->prefix = this->prefix-1;
    }

    void increaseEnd() {
        this->endsWith = this->endsWith+1;
    }

    void decreaseEnd() {
        if(endsWith > 0) this->endsWith = this->endsWith-1;

    }
    void increasePrefix() {
        this->prefix = this->prefix+1;
    }

    Node* next(char ch) {
        return this->links[ch-'a'];
    }

    int end() {
        return this->endsWith;
    }

    int pref() {
        return this->prefix;
    }



};

class Trie{

    Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
          if (!node->containsKey(word[i])) node->put(word[i]);
          node = node->next(word[i]);
          node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n;i++) {
            if(!node->containsKey(word[i])) return 0;
            node = node->next(word[i]);
        }

        return node->end();

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n;i++) {
            if(!node->containsKey(word[i])) return 0;
            node = node->next(word[i]);
        }

        return node->pref();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
          if(!node->containsKey(word[i])) return;
          node = node->next(word[i]);
          node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};
