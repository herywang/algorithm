/**
 * @file solution148.cpp
 * @author your name (you@domain.com)
 * @brief 排序链表
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *p = head->next;
        head->next = nullptr;
        while (p != nullptr) {
            ListNode *t = dummyHead;
            while (t->next != nullptr && p->val > t->next->val) {
                t = t->next;
            }
            ListNode *tmp = p;
            p = p->next;
            tmp->next = t->next;
            t->next = tmp;
        }
        return dummyHead->next;
    }
};

int main() {
    auto s = new Solution;
    ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    ListNode *res = s->sortList(head);
    print_list(res);
    delete s;
    return 0;
}