/**
 * @file solution505.cpp
 * @author your name (you@domain.com)
 * @brief 华为二面题目
 * 一个迷宫, 1表示墙, 0表示可以行走的区域, 找到从开始节点到目的地最短的距离
 * @version 0.1
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

void dfs(vector<vector<int>> &maze, vector<int> &start, vector<vector<int>> &distances) {
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (vector<int> dir : directions) {
        int x = start[0] + dir[0];
        int y = start[1] + dir[1];
        // 1 代表墙壁, 如果撞墙直接continue
        if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 1) {
            continue;
        }
        if (distances[start[0]][start[1]] + 1 < distances[x][y]) {
            distances[x][y] = distances[start[0]][start[1]] + 1;
            vector<int> newStart = {x, y};
            dfs(maze, newStart, distances);
        }
    }
}

/**
 * @brief 从开始位置走到结束位置最短路径
 *
 * @param maze 迷宫
 * @param start 开始位置
 * @param destination 目标位置
 * @return int 走到结束位置最短路径
 */
int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    assert(maze.size() > 0 && maze[0].size() > 0);
    vector<vector<int>> distances(maze.size(), vector<int>(maze[0].size(), INT_MAX));
    distances[start[0]][start[1]] = 0;
    dfs(maze, start, distances);
    return distances[destination[0]][destination[1]];
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> destination = {4, 4};
    int ans = shortestDistance(maze, start, destination);
    cout << ans << endl;
    return 0;
}
