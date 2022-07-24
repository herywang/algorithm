//
// Created by wangheng on 2021/6/21.
//
#ifndef MAC_ALGORITHM_VEC_UTIL_H
#define MAC_ALGORITHM_VEC_UTIL_H
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void print_list(ListNode *list) {
    ListNode *p = list;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
}

inline void free_list(ListNode* head){
    ListNode* p = head;
    while (p != nullptr){
        ListNode* t = p;
        p = p->next;
        delete t;
    }
}

#endif