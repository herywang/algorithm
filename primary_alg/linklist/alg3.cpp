//
// Created by wangheng on 2021/6/25.
// 快慢指针判断连表中是否存在环

#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* slow  = head;
        ListNode* fast  = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}
