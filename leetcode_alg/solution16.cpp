//
// Created by wangheng on 2021/6/17.
// 最接近target的三个数之和， 考察双指针解决方案
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3 || nums.size() > 1000) {
            throw "nums数量不合法!";
        } else {
            int ans = INT32_MAX;
            sort(nums.begin(), nums.end());
            int i = 0;
            while (i < nums.size()) {
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int i1 = nums[i] + nums[left] + nums[right] - target;
                    if (abs(i1) < abs(ans)) {
                        ans = i1;
                    }
                    if (i1 < 0) {
                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                    } else if (i1 > 0) {
                        right--;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    } else {
                        return target;
                    }
                }
                i++;
            }
            return ans + target;
        }
    }
};

int main() {
//    vector<int> nums = {-1,2,1,-4};
    vector<int> nums = {0, 0, 0};
    auto pSolution = new Solution;
    cout << pSolution->threeSumClosest(nums, 1) << endl;
    return 0;
}

