//
// Created by wangheng on 2022/8/18.
// 环形链表 II

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while (fast != nullptr) {
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // 快慢指针相遇
                ListNode *p = head;
                while (p != fast) {
                    p = p->next;
                    fast = fast->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

int main() {

    return 0;
}
