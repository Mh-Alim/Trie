
class Node{
    Node* links[26];
    bool flag = false;

    public: 

    bool contains(char ch) {
        if(links[ch-'a'] != nullptr) return true;
        return false;
    }

    void put(char ch) {
        links[ch-'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

};
class Trie {
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(!node->contains(word[i])) {
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node -> setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        Node* node = root;
        for(int i = 0; i < n;i++) {
            if(!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* node = root;
        for(int i = 0; i < n;i++) {
            if(!node->contains(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};