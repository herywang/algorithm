//
// Created by wangheng on 2022/7/21.
// 实现前缀树

#include <iostream>
#include <vector>

using namespace std;
class TrieNode{
public:
    // 值
    char c;
    // 当前节点是否是叶子节点
    bool isLeaf;
    // 孩子节点
    TrieNode *children[26];

    TrieNode(){
        this->c = 0;
        this->isLeaf = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }

    TrieNode(char _c, bool _isLeaf){
        this->c = _c;
        this->isLeaf = _isLeaf;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        _delete(this->root);
    }
    void _delete(TrieNode *node){
        if(node == nullptr){
            return;
        }
        for(int i = 0;i<26;i++){
            // 删除其孩子
            _delete(node->children[i]);
        }
        // 删除完成所有孩子之后,删除当前节点
        delete node;
    }

    void insert(string word) {
        TrieNode *p = this->root;
        for(int i = 0;i<word.length();i++){
            if(p->children[word[i] - 'a'] == nullptr){
                p->children[word[i] - 'a'] = new TrieNode(word[i], false);
            }
            p = p->children[word[i] - 'a'];
        }
        p->isLeaf = true;
    }

    bool search(string word) {
        TrieNode *p = this->root;
        for(int i = 0;i<word.length();i++){
            p = p->children[word[i] - 'a'];
            if(p == nullptr){
                return false;
            }
        }
        if(!p->isLeaf){
            return false;
        }
        return true;
    }

    bool startsWith(string prefix) {
        TrieNode *p = this->root;
        for(int i = 0;i<prefix.length();i++){
            p = p->children[prefix[i] - 'a'];
            if(p == nullptr){
                return false;
            }
        }
        return true;
    }
};

void testSolution(){
    auto s = new Trie;
    s->insert("apple");
    cout<<s->search("apple")<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
