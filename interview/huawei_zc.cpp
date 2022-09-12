/**
 * @file huawei_zc.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

typedef struct Node {
    int val;
    Node *next;
    Node(int _val, Node *_next) :
        val(_val), next(_next) {
    }
    Node(int _val) :
        val(_val) {
    }
} ListNode;

Node *findparent(Node *headA, Node *headB) {
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != nullptr && p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == nullptr) {
        p1 = headB;
        while (p2 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        p2 = headA;
    } else {
        p2 = headA;
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = headB;
    }
    while (p1 != p2 && p1 != nullptr && p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main(int argc, char *argv[]) {
    int N, M;
    cin >> N >> M;
    unordered_map<int, Node *> _map;
    for (int i = 0; i < N; i++) {
        _map[i] = new Node(i);
    }
    for (int i = 0; i < M; i++) {
        vector<int> path;
        int _t;
        while (cin >> _t) {
            path.push_back(_t);
            char ch = getchar();
            if (ch == '\n') {
                break;
            }
        }
        for (int j = 1; j < path.size(); j++) {
            // 创建链表
            _map[path[j]] = new Node(path[j], _map[path[0]]);
        }
    }

    int x, y;
    cin >> x >> y;
    Node *l1 = _map[x];
    Node *l2 = _map[y];

    // 寻找连个链表最近公共祖先
    Node *root = findparent(l1, l2);
    if (root == nullptr) {
        cout << -1 << endl;
        return 0;
    }
    Node *p1 = l1, *p2 = l2;
    int distance1 = 0, distance2 = 0;
    while (p1 != root) {
        distance1++;
        p1 = p1->next;
    }
    while (p2 != root) {
        distance2++;
        p2 = p2->next;
    }
    cout << distance1 + distance2 << endl;
    return 0;
}