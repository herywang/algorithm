//
// Created by wangheng on 2021/6/23.
// 矩阵旋转90°算法: 先上下交换, 再对角线交换
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhhkv/

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int len = matrix.size();
        if (len < 2)
            return;
        int mid = len >> 1;
        int t;

        // 先上下交换
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < len; j++) {
                t = matrix[i][j];
                matrix[i][j] = matrix[len - i - 1][j];
                matrix[len - 1 - i][j] = t;
            }
        }
        // 然后对角交换
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                t = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = t;
            }
        }
    }
};

int main() {
    vector<vector<int>> vec =
            {{1,  2,  3,  4,  5},
             {5,  6,  7,  8,  9},
             {9,  10, 11, 12, 90},
             {13, 14, 15, 16, 21},
             {23, 21, 9,  10, 18}};
    Solution *solution = new Solution;
    solution->rotate(vec);
    for (vector<int> v: vec) {
        print_vec(v);
    }
    return 0;
}
