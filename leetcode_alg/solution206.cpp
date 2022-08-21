//
// Created by wangheng on 2022/8/20.
// 反转链表
#include <vector>
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

void testSolution(){
    auto s = new Solution;
    ListNode* node = new ListNode(1,new ListNode(2, new ListNode(4, new ListNode(6))));
    auto pNode = s->reverseList(node);
    print_list(pNode);
    free_list(node);
    delete s;
}

int main(){
    testSolution();
    return 0;
}
