//
// Created by wangheng on 2022/8/9.
//

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode *> list;
        vector<ListNode *> stack;
        ListNode *p = head;

        while (p != nullptr) {
            list.emplace_back(p);
            p = p->next;
        }
        int i = 0, j = list.size() - 1;
        while (i <= j) {
            if (i == j) {
                stack.emplace_back(list[i++]);
            } else {
                stack.emplace_back(list[i++]);
                stack.emplace_back(list[j--]);
            }
        }
        for (int k = 0; k < stack.size() - 1; k++) {
            stack[k]->next = stack[k + 1];
        }
        stack[stack.size() - 1]->next = nullptr;
    }
};

int main() {

    return 0;
}
