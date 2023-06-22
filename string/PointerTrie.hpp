#include<bits/stdc++.h>

template<unsigned char_count = 26, int char_base = 'a'>
struct Trie {
    struct Node {
        Node* child[char_count];
        int char_n; // char_base_indexed
        int word_end_count;
        // 以下に任意の情報を追加

        // cというcharをもつ頂点を作成
        Node(int c) : char_n(c), word_end_count(0) {
            for(unsigned i=0; i<char_count; i++) child[i] = nullptr;
        }
    };
    Node* root = nullptr;

    Trie() { root = new Node(-1); }
    void insert(const std::string& s) {
        Node* now = root;
        for(int c : s) {
            c -= char_base;
            if(!now->child[c]) {
                now->child[c] = new Node(c);
            }
            now = now->child[c];
        }
        now->word_end_count++;
    }

    bool find(const std::string& s) const {
        Node* now = root;
        for(int c : s) {
            c -= char_base;
            if(!now->child[c]) return false;
            now = now->child[c];
        }
        return now->word_end_count > 0;
    }
};