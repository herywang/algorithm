//
// Created by wangheng on 2022/8/21.
// 滑动窗口最大值, 使用优先级队列

#include <iostream>
#include "vec_util.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        // 定义一个大顶堆
        priority_queue<pair<int, int>> p;
        for (int i = 0; i < k; i++) {
            p.emplace(nums[i], i);
        }
        vector<int> ans = {p.top().first};
        for (int i = k; i < n; i++) {
            p.emplace(nums[i], i);
            while (p.top().second <= i - k) {
                p.pop();
            }
            ans.emplace_back(p.top().first);
        }
        return ans;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto vector = s->maxSlidingWindow(nums, 3);
    print_vec(vector);
    delete s;
}

int main() {
    testSolution();
    return 0;
}


