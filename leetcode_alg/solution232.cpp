//
// Created by wangheng on 2022/7/24.
// 用栈实现队列

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {

    }

    void push(int x) {
        if(s2.empty()){
            s1.push(x);
        }else{
            // 将 s2中的元素移动到s1中，然后再push
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
        }
    }

    int pop() {
        int res = -1;
        if(!s2.empty()){
            res = s2.top();
            s2.pop();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            res = s2.top();
            s2.pop();
        }
        return res;
    }

    int peek() {
        int res = -1;
        if(!s2.empty()){
            res = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            res = s2.top();
        }
        return res;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {

    return 0;
}
