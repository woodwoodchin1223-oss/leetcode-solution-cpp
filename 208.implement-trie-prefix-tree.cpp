/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode {
public:
    bool isend;
    TrieNode* children[26];

    TrieNode() {
        isend = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    TrieNode* find(char c) {
        return this->children[c - 'a'];
    }

    bool exist(char c) {
        return this->children[c - 'a'] != nullptr;
    }

    void insert(char c) {
        this->children[c - 'a'] = new TrieNode();
    }

    bool isEnd() {
        return isend;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        cout << word << endl;
        for (int i = 0; i < word.length(); i++) {
            char current = word[i];
            cout << current << endl;
            if (node->exist(current) == false) {
                node->insert(current);
            }
            node = node->find(current);
        }
        node->isend = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char current = word[i];
            if (node->exist(current) == false) return false;
            node = node->children[current - 'a'];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char current = prefix[i];
            if (node->exist(current) == false) return false;
            node = node->children[current - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

