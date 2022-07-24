//
// Created by wangheng on 2021/6/25.
// 翻转链表, 借助栈存储结构

#include <iostream>
#include <vector>
#include "listnode.h"
#include "stack"

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        stack<ListNode*> stack1;
        ListNode* p = head;
        ListNode* emptyHead = new ListNode(-1, nullptr);
        while (p!= nullptr){
            stack1.push(p);
            p = p->next;
        }
        p = emptyHead;
        while (true){
            p->next = stack1.top();
            stack1.pop();
            p = p->next;
            if(stack1.empty()){
                p->next = nullptr;
                break;
            }
        }
        p = emptyHead;
        emptyHead = emptyHead->next;
        delete p;
        return emptyHead;
    }
};

int main() {

    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    Solution* solution = new Solution;
    ListNode *pNode = solution->reverseList(head);
    print_list(pNode);
    return 0;
}
