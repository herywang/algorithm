//
// Created by wangheng on 2022/8/20.
// 反转区间链表
#include <iostream>
#include "listnode.h"

using namespace std;

class Solution1 {
public:
    int findNthDigit(int n) {
        string str;
        for(int i = 1;i<=n;i++){
            str += to_string(i);
            if(str.size() >=n){
                break;
            }
        }
        const char c = str[n - 1];
        return atoi(&c);
    }
};

void testSolution1(){
    auto s = new Solution1;
    cout<<s->findNthDigit(13)<<endl;
    delete s;
}

class Solution {

private:
    void reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur!= nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 由于旋转的链表有可能从头结点开始, 因此使用虚拟的节点避免复杂的分类讨论
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;

        // 第一步: 从虚拟头节点走left - 1步,到达left节点的前一个节点
        for(int i = 0;i<left-1;i++){
            pre = pre->next;
        }

        // 第二步: 从pre再次走 right - left + 1步到达右节点
        ListNode* rightNode = pre;
        for(int i = 0;i<right - left + 1;i++){
            rightNode = rightNode->next;
        }

        // 第三步: 截断子链表
        ListNode* leftNode = pre->next;
        ListNode* curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第4步, 旋转子链表
        reverseList(leftNode);

        // 第5步: 接回到原来的链表中
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyHead->next;
    }
};

void testSolution() {
    auto s = new Solution;
    ListNode *head = new ListNode(1,
                                  new ListNode(2));

    auto pNode = s->reverseBetween(head, 1, 2);
    print_list(pNode);
    free_list(head);
    delete s;
}

int main() {
    testSolution1();
    return 0;
}
