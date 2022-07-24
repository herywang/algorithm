//
// Created by wangheng on 2022/7/22.
// 长度最小的连续子数组

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 执行超时。换成下面的方法。
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int res = INT_MAX;
        int sum = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            sum += nums[i];     //向右扩展窗口
            while (sum - nums[j] >= target) sum -= nums[j++]; //向左收缩窗口
            if (sum >= target) res = min(res, i - j + 1);    //区间更新
        }
        return res == INT_MAX ? 0 : res;
    }

};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {1, 4, 4};
    cout << s->minSubArrayLen(4, nums) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
