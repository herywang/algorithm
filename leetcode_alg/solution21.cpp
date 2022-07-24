//
// Created by wangheng on 2021/6/21.
// 合并两个有序升序链表
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *emptyHead = new ListNode(-1);
        ListNode* p = emptyHead;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val > p2->val){
                p->next = p2;
                p2 = p2->next;
            }else{
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        if(p1 == nullptr){
            p->next = p2;
        }else{
            p->next = p1;
        }
        ListNode* t = emptyHead;
        emptyHead = emptyHead->next;
        delete t;
        return emptyHead;
    }
};

int main(){
    ListNode* l1 = new ListNode(4, new ListNode(12, new ListNode(15)));
    ListNode* l2 = new ListNode(1, new ListNode(5, new ListNode(7)));
    Solution *s = new Solution;
    ListNode *result = s->mergeTwoLists(nullptr, l1);
    while(result != nullptr){
        cout<<result->val<<"->";
        result = result->next;
    }
    cout<<endl;
    return 0;
}