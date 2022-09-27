/**
 * @file solution503.cpp
 * @author your name (you@domain.com)
 * @brief 下一个更大元素 (单调栈)
 * @version 0.1
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    assert(nums.size() > 0);
    if (nums.size() == 1) {
        return {-1};
    }
    // 思路: 如果当前元素比栈顶元素小, 说明当前元素和栈顶元素的下一个更大元素相同,
    // 如果当前元素比栈顶元素大, 则逐个弹出栈, 直到栈为空或者当前元素小于栈顶元素, 说明栈里面的最大元素均为当前元素
    stack<int> _s;
    vector<int> ans(nums.size(), -1);
    for (int i = 0; i < nums.size() * 2; i++) {
        while (!_s.empty() && nums[i % nums.size()] > nums[_s.top()]) {
            ans[_s.top()] = nums[i % nums.size()];
            _s.pop();
        }
        _s.push(i % nums.size());
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> ans = nextGreaterElements(nums);
    for (auto &n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}