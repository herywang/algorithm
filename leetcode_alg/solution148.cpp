/**
 * @file solution148.cpp
 * @author your name (you@domain.com)
 * @brief 排序链表
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <algorithm>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        vector<int> array;
        ListNode* p = head;
        while(p != nullptr){
            array.push_back(p->val);
            p = p->next;
        }
        std::sort(array.begin(), array.end());
//        sort(array, 0, array.size()-1);
        p = head;
        int i = 0;
        while (p != nullptr){
            p->val = array[i++];
            p = p->next;
        }
        return head;
    }

private:
    void sort(vector<int> &array, int left, int right){
        if(left >= right){
            return;
        }
        int l = left;
        int r = right;
        int baseVal = array[left];
        while(l < r){
            // 从右往左找第一个比baseVal小的值
            while(r > l && array[r] >= baseVal){
                r--;
            }
            array[l] = array[r];
            // 从左往右找第一个比baseVal大的值
            while(l < r && array[l] <= baseVal){
                l++;
            }
            array[r] = array[l];
        }
        array[l] = baseVal;
        sort(array, left, l-1);
        sort(array, l+1, right);
    }
};

int main() {
    auto s = new Solution;
    vector<int> array = {4,19,14,5,-3,1,8,5,11,15};
    ListNode *head = buildList(array);
    ListNode *res = s->sortList(head);
    print_list(res);
    free_list(head);
    delete s;
    return 0;
}