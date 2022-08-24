//
// Created by wangheng on 2022/8/22.
// 华为笔试第二题

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution{
public:
    /**
     * @param nums 积木列表，每个积木大小
     * @param target 目标大小
     * @return 积木组合
     */
    vector<vector<int>> solution(vector<int> &nums, const int &target){
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> isVisited(nums.size(), false);
        int count = 0;//螺栓数量（偶数数量)
        sort(nums.begin(), nums.end());
        dfs(nums,ans, path, target, isVisited,0, count);
        return ans;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &path, int target,vector<bool> &isVisited, int start, int &count){
        if(count > 2){
            // 最多只能使用两个螺栓
            return;
        }
        if(target == 0){
            ans.emplace_back(path);
            return;
        }else if(target < 0){
            return;
        }
        for(int i = start;i<nums.size();i++){
            // 解决nums中含有重复数字
            if(i>0 && nums[i-1]==nums[i] && !isVisited[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            if(nums[i] % 2 == 0){
                count++;
            }
            isVisited[i] = true;
            dfs(nums, ans, path, target - nums[i],isVisited, i+1, count);
            if(nums[i] % 2 == 0){
                count--;
            }
            path.pop_back();
            isVisited[i] = false;
        }
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {2,3,1,1,4,5,6,7,8,6,6,3,4};
    auto ans = s->solution(nums, 8);
    for(vector<int> p:ans){
        print_vec(p);
    }
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}