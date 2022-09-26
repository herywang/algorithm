//
// Created by wangheng on 2022/7/27.
// 矩阵中最长递增路径

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int distance = 0;
    int row, col;

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        row = matrix.size();
        col = matrix[0].size();
        vector<vector<int>> memory(row, vector<int>(col, 0));
        int res = -1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs(i, j, memory, matrix));
            }
        }
        return res;
    }

    int dfs(int i, int j, vector<vector<int>> &memory, vector<vector<int>> &matrix) {
        if (memory[i][j] != 0) {
            // 记忆话搜索，如果当前grid被计算过了，就直接返回
            return memory[i][j];
        }
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxLen = 1;
        for (auto dir : dirs) {
            int nextI = i + dir[0];
            int nextJ = j + dir[1];
            if (nextI >= 0 && nextI < row && nextJ >= 0 && nextJ < col && matrix[nextI][nextJ] > matrix[i][j]) {
                maxLen = max(maxLen, dfs(nextI, nextJ, memory, matrix) + 1);
            }
        }
        memory[i][j] = maxLen;
        return maxLen;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}};
    int res = s->longestIncreasingPath(matrix);
    cout << res << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
