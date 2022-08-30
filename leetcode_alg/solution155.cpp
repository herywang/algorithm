/**
 * @file solution155.cpp
 * @author your name (you@domain.com)
 * @brief 最小栈
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> _s;

public:
    MinStack() {
    }

    void push(int val) {
        if (_s.empty()) {
            _s.push({val, val});
        } else {
            _s.push({val, min(val, _s.top().second)});
        }
    }

    void pop() {
        _s.pop();
    }

    int top() {
        return _s.top().first;
    }

    int getMin() {
        return _s.top().second;
    }
};

int main() {
    return 0;
}