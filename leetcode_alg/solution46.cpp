//
// Created by wangheng on 2022/7/14.
//

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        vector<int> path;
        vector<bool> isUsed(nums.size(),false);
        dfs(nums, res, path, isUsed);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, vector<bool> &isUsed){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!isUsed[i]){
                path.emplace_back(nums[i]);
                isUsed[i] = true;
                dfs(nums, res, path, isUsed);
                isUsed[i] = false;
                path.pop_back();
            }
        }
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {2,3,4,5};
    vector<vector<int>> res = s->permute(nums);
    for(vector<int> v : res){
        print_vec(v);
    }
    return 0;
}
