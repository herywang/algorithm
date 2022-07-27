//
// Created by wangheng on 2022/7/27.
// 矩阵中最长递增路径
// TODO 未做出来

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int distance = 0;

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        vector<vector<bool>> isVisited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int maxValue = -1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int res = dfs(matrix, i, j, 0, isVisited);
                maxValue = std::max(maxValue, res);
            }
        }
        return maxValue;
    }


    int dfs(vector<vector<int>> &matrix, int x, int y, int preNum, vector<vector<bool>> &isVisited) {
        if (!inArea(matrix, x, y) || isVisited[x][y]) {
            return 0;
        }
        isVisited[x][y] = true;
        if (matrix[x][y] <= preNum) {
            isVisited[x][y] = false;
            return 0;
        }

        int res1 = dfs(matrix, x - 1, y, matrix[x][y], isVisited);
        isVisited[x][y] = false;
        int res2 = dfs(matrix, x + 1, y, matrix[x][y], isVisited);
        isVisited[x][y] = false;
        int res3 = dfs(matrix, x, y - 1, matrix[x][y], isVisited);
        isVisited[x][y] = false;
        int res4 = dfs(matrix, x, y + 1, matrix[x][y], isVisited);
        isVisited[x][y] = false;
        return 1 + this->max(res1, res2, res3, res4);
    }


private:
    inline bool inArea(vector<vector<int>> &matrix, int x, int y) {
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) {
            return false;
        }
        return true;
    }

    int max(int &a, int &b, int &c, int &d) {
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        tmp.push_back(d);
        sort(tmp.begin(), tmp.end());
        return tmp[3];
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> matrix = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
    };
    int res = s->longestIncreasingPath(matrix);
    cout << res << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
