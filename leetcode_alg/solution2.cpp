//
// Created by wangheng on 2022/7/14.
//

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode;
        ListNode *cur = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum, nullptr);
            cur->next = node;
            cur = node;
        }
        if (carry == 1) {
            cur->next = new ListNode(carry);
        }
        return head->next;
    }
};

int main() {
    auto s = new Solution;
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *res = s->addTwoNumbers(l1, l2);
    print_list(res);
    return 0;
}