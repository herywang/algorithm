/**
 * @file solution162.cpp
 * @author your name (you@domain.com)
 * @brief 寻找峰值
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int N = nums.size();
        int l = 0, r = N - 1;
        int m;
        nums.push_back(INT_MIN);
        while (l <= r) {
            m = (l + r) >> 1;
            if (nums[m] > nums[m + 1]) {
                // 峰在左边
                r = m - 1;
            } else {
                // 峰在右边
                l = m + 1;
            }
        }
        return l;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << s->findPeakElement(nums) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
