//
// Created by wangheng on 2022/7/23.
//

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    char c;
    bool isLeaf;
    TrieNode *children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    TrieNode(char c, bool isLeaf) {
        TrieNode();
        this->c = c;
        this->isLeaf = isLeaf;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        this->root = new TrieNode();
    }

    ~WordDictionary() {
        _delete(this->root);
    }

    void _delete(TrieNode *node) {
        if (node == nullptr) {
            return;
        }
        for (int i = 0; i < 26; i++) {
            // 删除其孩子
            _delete(node->children[i]);
        }
        // 删除完成所有孩子之后,删除当前节点
        delete node;
    }


    void addWord(string word) {
        TrieNode *p = this->root;
        for (int i = 0; i < word.size(); i++) {
            if (p->children[word[i] - 'a'] == NULL) {
                p->children[word[i] - 'a'] = new TrieNode(word[i], false);
            }
            p = p->children[word[i] - 'a'];
        }
        p->isLeaf = true;
    }

    bool search(string word) {
        return _doSearch(this->root, word, 0);
    }

    bool _doSearch(TrieNode *p, string &word, int index){
        if(p == nullptr){
            return false;
        }
        if(index == word.size()){
            return p->isLeaf;
        }
        if(word[index] != '.'){
            return _doSearch(p->children[word[index] - 'a'], word, index+1);
        }else{
            for(int i = 0;i<26;i++){
                if(_doSearch(p->children[i], word, index+1)){
                    return true;
                }
            }
        }
        return false;
    }
};

void testSolution(){
    auto s = new WordDictionary;
    s->addWord("hello");
    s->addWord("how");
    s->addWord("are");
    s->addWord("you");
    cout<<s->search("hallo")<<endl;
    delete s;
}
int main() {
    testSolution();
    return 0;
}
