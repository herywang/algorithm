//
// Created by wangheng on 2021/6/22.
// 组合数总和Ⅱ，每个数字只能使用一次
#include "iostream"
#include "vector"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> isUsed(candidates.size(), false);

        if(candidates.size()==0){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, path, 0);
        return res;
    }

    void dfs(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> path, int begin){
        if(target == 0){
            res.emplace_back(path);
            return;
        }
        for(int i = begin;i<candidates.size();i++){
            if(target - candidates[i] < 0){
                break;
            }
            if(i>begin && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, path, i+1);
            path.pop_back();
        }
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> num = {10,1,2,7,6,1,5};

    vector<vector<int>> res = s->combinationSum2(num, 8);
    for(vector<int> v:res){
        print_vec(v);
    }
}

int main(){
    testSolution();
    return 0;
}
