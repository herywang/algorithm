//
// Created by wangheng on 2021/6/25.
// 回文链表

#include <iostream>
#include <vector>
#include "listnode.h"
#include "stack"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        stack<int> stack1;
        ListNode* p = head;
        while (p!= nullptr){
            stack1.push(p->val);
            p = p->next;
        }
        p = head;
        while (p!= nullptr){
            if(p->val != stack1.top()){
                return false;
            }else{
                stack1.pop();
                p = p->next;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}
