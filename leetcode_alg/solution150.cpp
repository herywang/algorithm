//
// Created by wangheng on 2022/8/9.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> _stack;
        for (string &s : tokens) {
            if (s.length() == 1 && s[0] == '+') {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                _stack.push(a + b);
            } else if (s.length() == 1 && s[0] == '-') {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                _stack.push(b - a);
            } else if (s.length() == 1 && s[0] == '*') {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                _stack.push(a * b);
            } else if (s.length() == 1 && s[0] == '/') {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                _stack.push(b / a);
            } else {
                int a = atoi(s.c_str());
                _stack.push(a);
            }
        }
        return _stack.top();
    }
};

void testSolution() {
    auto s = new Solution;
    vector<string> strings = {"4", "13", "5", "/", "+"};
    cout << s->evalRPN(strings) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
