//
// Created by wangheng on 2021/6/21.
// 两两交换相邻节点
#include "iostream"
#include "listnode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* emptyHead = new ListNode(-1, head);
        // EmptyHead  ->  a  ->  b  ->  c   -> null
        //   ^            ^      ^
        //   p1           p2     p3
        ListNode* p1 = emptyHead;
        ListNode* p2 = emptyHead->next;
        ListNode* p3 = emptyHead->next->next;
        ListNode* tmp;
        while(p2 != nullptr && p3 != nullptr){
            p2->next = p3->next;
            p3->next = p2;
            p1->next = p3;

            tmp = p2;
            p2 = p3;
            p3 = tmp;

            if(p2->next != nullptr && p2->next->next != nullptr){
                p2 = p2->next->next;
            }else{
                break;
            }
            p3 = p3->next->next;
            p1 = p1->next->next;
        }
        ListNode* t = emptyHead;
        emptyHead = emptyHead->next;
        delete t;
        return emptyHead;
    }
};

int main(){
    Solution* solution = new Solution;

    ListNode *pNode = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(9)))));
    ListNode *head = solution->swapPairs(pNode);
    while(head != nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    return 0;
}

