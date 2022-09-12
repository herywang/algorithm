/**
 * @file solution496.cpp
 * @author your name (you@domain.com)
 * @brief 下一个更大元素，单调栈
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solve(vector<int> &nums) {
    stack<int> _stack;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (_stack.empty()) {
            _stack.push(nums[i]);
        } else {
            while (!_stack.empty() && nums[i] <= _stack.top()) {
                _stack.pop();
            }
            if (!_stack.empty()) {
                ans += (nums[i] - _stack.top());
                _stack.pop();
            }
            _stack.push(nums[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    int _t;
    while (cin >> _t) {
        nums.push_back(_t);
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
    cout << solve(nums) << endl;
    return 0;
}
