//
// Created by wangheng on 2021/6/21.
// 合并k个升序链表 分而治之的思想，
#include "iostream"
#include "vector"
#include "listnode.h"

using namespace std;



class Solution {
public:
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* emptyHead = new ListNode(-1);
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* p = emptyHead;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }else{
                p->next = p2;
                p2 = p2->next;
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

    ListNode* merge(vector<ListNode*> list, int left, int right){
        if(left == right){
            return list[left];
        }else{
            int mid = (left+right) >> 1;
            ListNode* l1 = merge(list, left, mid);
            ListNode* l2 = merge(list, mid+1, right);
            return mergeTwoList(l1, l2);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() < 2){
            return lists.at(0);
        }else{
            int left = 0;
            int right = lists.size()-1;
            return merge(lists, left, right);
        }
    }
};

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(7, new ListNode(10))));
    ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(8))));
    ListNode* l3 = new ListNode(1, new ListNode(3, new ListNode(9, new ListNode(18))));
    vector<ListNode*> lists = {l1, l2, l3};
    const auto s = new Solution;
    ListNode* pNode = s->mergeKLists(lists);
    while(pNode != nullptr){
        cout<<pNode->val<<"->";
        pNode = pNode->next;
    }
    cout<<endl;
    return 0;
}



