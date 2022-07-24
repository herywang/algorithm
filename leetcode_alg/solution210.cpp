//
// Created by wangheng on 2022/7/23.
// 课程表

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if(numCourses == 0){
            return res;
        }
        // 入度
        vector<int> inDegree(numCourses, 0);
        // 依赖关系
        unordered_map<int, vector<int>> dependency;
        for(int i = 0;i<prerequisites.size();i++){
            vector<int> v = prerequisites[i];
            inDegree[v[0]] ++;
            dependency[v[1]].push_back(v[0]);
        }
        queue<int> q;
        // 查找入度为0的点
        for(int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0){
                res.push_back(i);
                q.push(i);
            }
        }
        while (!q.empty()){
            int p = q.front();
            vector<int> dep = dependency[p];
            // 将依赖此课程的后续课程入读减1
            for(int i:dep){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    q.push(i);
                    res.push_back(i);
                }
            }
            q.pop();
        }

        if(res.size() != numCourses){
            return {};
        }
        return res;
    }
};

void testSolution(){
    auto s = new Solution;
    vector<vector<int>> prerequires = {{1,0},{2,0},{3,1},{3,2}};
    const vector<int> &order = s->findOrder(4, prerequires);
    for(int i:order){
        cout<<i <<" ";
    }
    cout<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
