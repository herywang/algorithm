//
// Created by wangheng on 2022/7/13.
// 搜索矩阵

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        // 思路，从右上角开始，往左减小，往下增大
        int row = 0, col = matrix[0].size()-1;
        while (row != matrix.size() && col != -1){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                col--;
            }else {
                row++;
            }
        }
        return false;
    }
};

int main() {
    auto solution = new Solution;
    vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 12, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    cout<<solution->searchMatrix(matrix,20)<<endl;
    return 0;
}
