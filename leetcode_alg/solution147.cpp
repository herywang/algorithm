/**
 * @file solution147.cpp
 * @author your name (you@domain.com)
 * @brief 对链表进行插入排序
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *latestSorted = dummyHead->next;
        ListNode *current = latestSorted->next;
        while (current != nullptr) {
            if (latestSorted->val <= current->val) {
                latestSorted = latestSorted->next;
            } else {
                ListNode *p = dummyHead;
                while (p->next->val <= current->val) {
                    p = p->next;
                }
                latestSorted->next = current->next;
                current->next = p->next;
                p->next = current;
            }
            current = latestSorted->next;
        }
        return dummyHead->next;
    }
};

void testSolution() {
    auto s = new Solution;
    // ListNode *node = new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1))));
    ListNode *node = new ListNode(1, new ListNode(1));
    auto ans = s->insertionSortList(node);
    print_list(ans);
    free_list(node);
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
}