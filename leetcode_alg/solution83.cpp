//
// Created by wangheng on 2021/7/18.
// 升序链表删除重复的元素

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head== nullptr || head->next == nullptr){
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* t;
        while (q != nullptr){
            if(q->val == p->val){
                t = q;
                p->next = q->next;
                q = q->next;
                delete t;
            }else{
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1,new ListNode(1, new ListNode(2,new ListNode(3, new ListNode(3)))));
    auto solution = new Solution;
    solution->deleteDuplicates(head);
    print_list(head);
    delete solution;
    free_list(head);
    return 0;
}
