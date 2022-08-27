//
// Created by wangheng on 2022/8/26.
// 排序矩阵查找

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int row = matrix.size();

        int currentRow = 0;
        int currentCol = matrix[0].size() - 1;
        while (currentRow < row && currentCol >= 0) {
            if (matrix[currentRow][currentCol] == target) {
                return true;
            } else if (matrix[currentRow][currentCol] > target) {
                currentCol--;
            } else {
                currentRow++;
            }
        }
        return false;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> matrix = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    cout<<s->searchMatrix(matrix, 20)<<endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}