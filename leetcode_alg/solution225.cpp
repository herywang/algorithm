//
// Created by wangheng on 2022/8/19.
// 用队列实现栈

#include <iostream>
#include <vector>
#include "deque"

using namespace std;

class MyStack {
private:
    deque<int> dq;
public:
    MyStack() {
        
    }

    void push(int x) {
        dq.push_back(x);
    }

    int pop() {
        int i = dq.back();
        dq.pop_back();
        return i;
    }

    int top() {
        return dq.back();
    }

    bool empty() {
        return dq.empty();
    }
};

int main() {

    return 0;
}
