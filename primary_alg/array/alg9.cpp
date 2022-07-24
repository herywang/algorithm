//
// Created by wangheng on 2021/6/23.
// 两数之和

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    // 方法1: 两个for循环,暴力破解
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        if (nums.size() < 2) {
            return ans;
        } else {
            for (int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
            return ans;
        }
    }

    // 方法二: map集合
    vector<int> twoSum2(vector<int> &nums, int target){

    }
};

int main() {

    Solution *solution = new Solution;
    vector<int> nums = {2, 7, 11, 5};
    int target = 9;
    vector<int> sum = solution->twoSum(nums, target);
    print_vec(sum);
    return 0;
}
