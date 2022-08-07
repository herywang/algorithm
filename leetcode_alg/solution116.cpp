//
// Created by wangheng on 2022/8/7.
// 填充每个节点的下一个右侧节点指针

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int val) {
        this->val = val;
        this->left = this->right = this->next = NULL;
    }
    Node(int val, Node *left, Node *right, Node *next) {
        this->val = val;
        this->left = left;
        this->right = right;
        this->next = next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* pre = nullptr;
            for(int i = 0;i<size;i++){
                Node *&pNode = q.front();
                if(pNode->left != nullptr){
                    q.push(pNode->left);
                }
                if(pNode->right != nullptr){
                    q.push(pNode->right);
                }
                if(pre != nullptr){
                    pre->next = pNode;
                }
                pre = pNode;
                q.pop();
            }
            pre->next = nullptr;
        }
        return root;
    }
};

void deleteNode(Node *node){
    if(node == nullptr){
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

void testSolution(){
    auto s = new Solution;
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr),
            new Node(3, new Node(6), new Node(7), nullptr), nullptr);
    s->connect(root);
    deleteNode(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
