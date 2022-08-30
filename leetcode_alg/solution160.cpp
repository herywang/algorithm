/**
 * @file solution160.cpp
 * @author your name (you@domain.com)
 * @brief 查找相交链表的开始相交位置
 * @version 0.1
 * @date 2022-08-30
 * 算法思路：首先去除长度差
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == nullptr) {
            p1 = headB;
            while (p2 != nullptr) {
                p2 = p2->next;
                p1 = p1->next;
            }
            p2 = headA;
        } else {
            p2 = headA;
            while (p1 != nullptr) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = headB;
        }
        while (p1 != p2 && p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

void testSolution() {
    auto s = new Solution;

    ListNode *common = new ListNode(11, new ListNode(12, new ListNode(13)));
    ListNode *headA = new ListNode(1, new ListNode(2, common));
    ListNode *headB = new ListNode(8, new ListNode(9, new ListNode(10, common)));
    ListNode *ans = s->getIntersectionNode(headA, headB);
    print_list(ans);
    free_list(headA);
    free_list(headB);
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
}