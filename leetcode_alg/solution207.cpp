//
// Created by wangheng on 2022/7/20.
// 拓扑排序

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses <= 0) {
            return true;
        }
        // 每个课程的入度
        vector<int> inDegree(numCourses, 0);
        // 依赖当前课程的后序课程
        unordered_map<int, vector<int>> map;
        for(auto v:prerequisites){
            // 更新当前课程的入度
            inDegree[v[0]]++;
            // 添加依赖的后序课程
            map[v[1]].push_back(v[0]);
        }
        queue<int> Qu;
        // 将所有入度为0的节点添加到队列中
        for(int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0){
                Qu.push(i);
            }
        }
        int count = 0;
        while(Qu.size()>0){
            int q = Qu.front();
            Qu.pop();
            count++;
            auto vector1 = map[q];
            if(vector1.size() > 0){
                for(int i = 0;i<vector1.size();i++){
                    inDegree[vector1[i]]--;
                    if(inDegree[vector1[i]] == 0){
                        Qu.push(vector1[i]);
                    }
                }
            }

        }
        if(count != numCourses){
            return false;
        }
        return true;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> prerequires = {
            {3,0}, {3,1}, {4,1}, {4,2}, {5,3}, {5,4}
    };
    cout<<s->canFinish(6, prerequires)<<endl;
}

int main() {
    testSolution();
    return 0;
}
