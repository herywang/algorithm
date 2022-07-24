//
// Created by wangheng on 2022/7/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> isUsed(nums.size(), false);
        if(nums.size() == 0){
            return res;
        }
        // 先对数组中的数据进行排序，用于后续的去重
        sort(nums.begin(), nums.end());
        dfs(res, nums, path, isUsed);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &path, vector<bool> &isUsed){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(isUsed[i]){
                // 如果第i个元素被使用过了，则跳过当前元素
                continue;
            }
            if(i > 0 && nums[i] == nums[i-1] && !isUsed[i-1]){
                continue;
            }
            path.emplace_back(nums[i]);
            isUsed[i] = true;
            dfs(res, nums, path, isUsed);
            path.pop_back();
            isUsed[i] = false;
        }
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {1,2,2,3};
    vector<vector<int>> res = s->permuteUnique(nums);
    for(vector<int> v: res){
        print_vec(v);
    }
    return 0;
}
