//
// Created by wangheng on 2022/7/26.
//

#include <iostream>
#include <vector>
#include "vec_util.h"

#define M 999

using namespace std;

class Solution {
public:
    vector<int> dijkstra(vector<vector<int>> &graph, int start) {
        int N = graph.size();
        // 记录开始节点到 i 节点的最短距离
        vector<int> distance(N, INT_MAX);
        // 用一个数据记录节点 i 是否被访问过
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            distance[i] = graph[start][i];
        }

        // 每次遍历，更新一个点的最短距离，因此需要遍历N次，才能更新全部 start节点到其他节点的距离（包含start节点本身)
        for (int i = 0; i < N; i++) {
            int minValue = INT_MAX;
            int minNode = 0;
            for (int j = 0; j < N; j++) {
                if (visited[j]) {
                    continue;
                }
                if (distance[j] < minValue) {
                    minValue = distance[j];
                    minNode = j;
                }
            }
            visited[minNode] = true;
            // 更新 start 节点到其他节点的最短距离
            for (int k = 0; k < N; k++) {
                if (k == start) {
                    continue;
                }
                if (distance[minNode] + graph[minNode][k] < distance[k]) {
                    // 如果 start 到 k的距离 小于 start -> minNode -> k的距离，则更新distance[
                    distance[k] = distance[minNode] + graph[minNode][k];
                }
            }
        }
        return distance;
    }
};

void testSolution() {
    auto s = new Solution;
    // 有向图邻接矩阵
    vector<vector<int>> graph = {
            {0, 10, 3, M, M},
            {M, 0,  1, 2, M},
            {M, M,  0, 8, 2},
            {M, M, M,  0, 7},
            {M, M, M,  M, 0}
    };
    const vector<int> &res = s->dijkstra(graph, 0);
    print_vec(res);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
