//
// Created by wangheng on 2021/6/22.
// 组合数总和： 回溯 + 剪枝方法
#include "vector"
#include "iostream"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param candidates 排好序的数组
     * @param target 目标值
     * @return
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(ans, candidates, combine,0, target);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& candidates,vector<int>& combine,  int idx, const int& target){
        if(idx == candidates.size()){
            return;
        }
        if(target == 0){
            ans.emplace_back(combine);
            return;
        }
        dfs(ans, candidates, combine,idx+1,target);
        if(target-candidates[idx] >= 0){
            combine.emplace_back(candidates[idx]);
            dfs(ans, candidates,combine,idx, target-candidates[idx]);
            combine.pop_back();
        }
    }
};

// 组合数总和，2刷
class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        if(candidates.size()==0){
            return res;
        }
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target, res, path, 0);
        return res;
    }

    void dfs(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &path, int begin){
        if(target == 0){
            res.emplace_back(path);
            return;
        }else if(target < 0){
            return;
        }
        for(int i = begin;i<candidates.size();i++){
            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, path, i);
            path.pop_back();
        }
    }
};

void testSolution(){
    Solution *solution = new Solution;
    vector<int> candidates = {1,2,3,4,5};
    const vector<vector<int>> &sum = solution->combinationSum(candidates, 4);
    for(vector<int> vs:sum){
        cout<<"[";
        for(int i:vs){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }
}

void testSolution1(){
    auto s = new Solution1;
    vector<int> candidates = {1,2,3,4,5};
    vector<vector<int>> res = s->combinationSum(candidates, 4);
    for(vector<int> v:res){
        print_vec(v);
    }
}

int main(){
    testSolution1();
    return 0;
}

