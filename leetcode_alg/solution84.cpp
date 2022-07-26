//
// Created by wangheng on 2022/7/26.
// 删除排序链表中的重复元素

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *p = dummyHead;
        while (p->next != nullptr && p->next->next != nullptr) {
            if (p->next->val == p->next->next->val) {
                int x = p->next->val;
                while (p->next != nullptr && p->next->val == x) {
                    ListNode *tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;
                }
            } else {
                p = p->next;
            }
        }
        ListNode *t = dummyHead->next;
        delete dummyHead;
        return t;
    }
};

void testSolution() {
    auto s = new Solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3,
            new ListNode(3, new ListNode(4, new ListNode(4,
                    new ListNode(5)))))));
    ListNode *pNode = s->deleteDuplicates(head);
    print_list(pNode);
    free_list(pNode);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
