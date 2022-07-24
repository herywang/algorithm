//
// Created by wangheng on 2021/6/30.
// 杨辉三角

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows < 0)
            return ans;
        // 第0行
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            for (int j = 1; j < i; j++) {
                int val = ans[i - 1][j - 1] + ans[i - 1][j];
                row.push_back(val);
            }
            row.push_back(1);
            ans.push_back(row);
        }

    }
};

int main() {

    Solution *solution = new Solution;
    vector<vector<int>> ans = solution->generate(8);
    for (vector<int> vec:ans) {
        print_vec(vec);
    }
    return 0;
}
