//
// Created by wangheng on 2021/6/20.
// 一趟遍历,删除链表倒数第n个节点 : 双指针方式解决
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* node = new ListNode(-1, head);
        ListNode* p = node;
        ListNode* q = node;
        for(int i = 0;i<n+1;i++){
            q = q->next;
        }
        while(q != nullptr){
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        ListNode* realHead = node->next;
        delete node;
        return realHead;
    }
};

int main(){
    auto s = new Solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *p = s->removeNthFromEnd(head, 5);
    while(p != nullptr){
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;
    return 0;
}
