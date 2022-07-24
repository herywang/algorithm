//
// Created by wangheng on 2022/7/17.
// 子集给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        if (nums.size() <= 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        dfs(nums, res, path, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, int begin) {
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++) {
            if (i > begin && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, res, path, i + 1);
            path.pop_back();
        }

    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = s->subsetsWithDup(nums);
    for (vector<int> v: res) {
        print_vec(v);
    }
}

int main() {
    testSolution();
    return 0;
}
