//
// Created by wangheng on 2021/6/29.
// 回溯算法求解全排列

#include <vector>
#include "vec_util.h"

using namespace std;


class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> nums;
    vector<bool> isUsed = {false};
public:
    vector<vector<int>> permute(vector<int> &nums) {
        this->nums = nums;
        if (nums.size() < 1)
            return ans;
        dfs(0);
        return ans;
    }

    /**
     * 深度遍历
     */
    void dfs(int depth) {
        if (depth == nums.size()) {
            vector<int> outarray(this->path);
            ans.push_back(outarray);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!isUsed[i]) {
                path.push_back(nums[i]);
                isUsed[i] = true;
                dfs(depth + 1);
                path.pop_back();
                isUsed[i] = false;
            }
        }
    }
};

int main() {
    Solution *solution = new Solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = solution->permute(nums);
    for (vector<int> v: ans) {
        print_vec(v);
    }
    return 0;
}
