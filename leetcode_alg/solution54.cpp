//
// Created by wangheng on 2021/7/21.
// 螺旋矩阵

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>> &matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int up = 0;
        int down = rows;
        int left = 0;
        int right = cols;
        while (up < down && left < right) {
            // 从左往右遍历
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[up][i]);
            }
            up ++;
            //从上往下遍历
            for (int i = up; i < down; i++) {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;
            // 从右往左遍历
            if(up < down){
                for (int i = right - 1; i >= left; i--) {
                    ans.push_back(matrix[down - 1][i]);
                }
                down--;
            }
            // 从下往上遍历
            if(left < right){
                for (int i = down - 1; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

        }
        return ans;
    }
};

int main() {
//    vector<vector<int>> matrix = {{1,  2,  3,  4,  5},
//                                  {6,  7,  8,  9,  10},
//                                  {11, 12, 13, 14, 15},
//                                  {16, 17, 18, 19, 20}};
    vector<vector<int>> matrix = {{1},{2},{3}};
    auto solution = new Solution;
    vector<int> ans = solution->spiralOrder(matrix);
    print_vec(ans);
    delete solution;
    return 0;
}
