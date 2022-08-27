//
// Created by wangheng on 2022/8/27.
//
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p = head;
        ListNode *end = nullptr;
        int n = 0;
        while (p != nullptr) {
            end = p;
            p = p->next;
            n++;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (k > 0) {
            fast = fast->next;
            k--;
        }
        while (fast != end) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return tmp;
    }
};

void testSolution() {
    auto s = new Solution;
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(3,
                                                                  new ListNode(4, new ListNode(5)))));
    auto pNode = s->rotateRight(root, 3);
    print_list(pNode);
    free_list(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
