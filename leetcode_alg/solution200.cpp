//
// Created by wangheng on 2022/6/18.
// 岛屿数量问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() < 1) {
            return 0;
        }
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                int _area = area(grid, r, c);
                if (_area > 0) {
                    res++;
                }
            }
        }
        return res;
    }

    int area(vector<vector<char>> &grid, int r, int c) {
        if (!inArea(grid, r, c)) {
            return 0;
        }
        if (grid[r][c] != '1') {
            return 0;
        }
        grid[r][c] = '2';
        return 1 + area(grid, r - 1, c)
               + area(grid, r + 1, c)
               + area(grid, r, c - 1)
               + area(grid, r, c + 1);
    }

    bool inArea(vector<vector<char>> &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};

    vector<vector<char>> grid1 = {
            {'1', '0', '1', '1', '0', '1', '1'}
    };
    Solution *s = new Solution;
    int res = s->numIslands(grid1);
    cout<<res<<endl;
    return 0;
}
