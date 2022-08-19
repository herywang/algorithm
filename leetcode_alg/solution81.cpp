//
// Created by wangheng on 2022/7/24.
// 搜索旋转数组II

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int mid_l = 0, mid_r = nums.size() - 1;
        if (nums.size() == 0) {
            return false;
        } else if (nums.size() == 1) {
            return nums[0] == target;
        }
        // 找到中间分界点
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                mid_l = i - 1;
                mid_r = i;
                break;
            }
        }
        // [0, mid_l] 单调递减
        // [mid_r, nums.size-1]单调递增
        // 判断target在哪一节
        int l, r, mid;
        if (mid_l == 0 && mid_r == nums.size() - 1) {
            l = 0;
            r = mid_r;
        } else if (target >= nums[mid_r] && target <= nums[nums.size() - 1]) {
            // 在右边一节
            l = mid_r;
            r = nums.size() - 1;
        } else {
            l = 0;
            r = mid_l;
        }
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == nums[mid]) {
                return true;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {1, 3, 5};
    vector<int> nums3 = {3,1};
    cout << s->search(nums3, 1) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
