//
// Created by wangheng on 2022/7/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 找到从节点：startNode到节点endNode的最小代价路径
     * @param table 领接表，存储有向图的关系
     * @param values 每个节点的权值
     */
    void resolve(unordered_map<int, vector<int>> table, vector<int> &values, int startNode, int endNode, int N) {
        //
        vector<int> distance(N, INT_MAX);

        distance[startNode] = 0;

        vector<int> &v = table[startNode];
        for (int i: v) {
            // 初始化开始节点到每个顶点的距离
            distance[i] = values[startNode] + values[i];
        }
        for(int i:v){

        }


    }

};

int main() {

    return 0;
}
