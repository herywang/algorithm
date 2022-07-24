//
// Created by wangheng on 2022/7/21.
//

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *tmpHead = new ListNode(-1, head);
        ListNode *p = tmpHead;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode *t = p->next;
                p->next = t->next;
                delete t;
            } else {
                p = p->next;
            }
        }
        return tmpHead->next;
    }
};

void testSolution() {
    auto s = new Solution;
    ListNode *node = new ListNode(1,
                                  new ListNode(2,
                                               new ListNode(6,
                                                            new ListNode(3,
                                                                         new ListNode(4,
                                                                                      new ListNode(5,
                                                                                                   new ListNode(
                                                                                                           6)))))));
    ListNode *pNode = s->removeElements(node, 6);
    while(pNode != nullptr){
        cout<<pNode->val<<endl;
        pNode = pNode->next;
    }
}

int main() {
    testSolution();
    return 0;
}
