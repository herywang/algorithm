//
// Created by wangheng on 2022/6/18.
//

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *p = head;
        Node *tmp = new Node(insertVal);
        while (p->next != head) {
            if (insertVal >= p->val && insertVal <= p->next->val) {
                // 插入节点数据位于 当前节点数据和下一节点数据之间
                tmp->next = p->next;
                p->next = tmp;
                return head;
            } else if (p->val > p->next->val && (insertVal > p->val || insertVal <= p->next->val)) {
                // 插入的数据val比当前节点数据大，并且当前节点数据比下一节点数据大
                tmp->next = p->next;
                p->next = tmp;
                return head;
            }
            p = p->next;
        }
        tmp->next = head;
        p->next = tmp;
        return head;
    }
};


int main() {
    Solution* s = new Solution;
    Node* head = s->insert(nullptr, 3);
    head = s->insert(head, 3);
    head = s->insert(head, 5);
    head = s->insert(head, 0);


    Node* tmp = head;
    while (true){
        cout<<tmp->val<<"-";
        if(tmp->next == head){
            return 0;
        }
        tmp = tmp->next;
    }
    return 0;
}
