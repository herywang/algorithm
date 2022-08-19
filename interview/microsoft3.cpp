//
// Created by wangheng on 2022/8/19.
//

#include <iostream>
#include <vector>

using namespace std;
// 所有入度都为0
bool isTrue(int *degree, int N){
    for(int i = 0;i<N;i++){
        if(degree[i]==1){
            return false;
        }
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int N = -1;
    for(auto _a:A){
        if(_a>N){
            N = _a;
        }
    }
    for(auto _a:B){
        if(_a>N){
            N = _a;
        }
    }
    N += 1;
    int cap = 5;//座位限制
    int *degree = new int[N]{0};
    int *count = new int[N];
    for(int i = 0;i<N;i++){
        count[i] = 1;
    }
    int fule = 0;//燃料
    // 定义领接矩阵
    vector<vector<int>> graph;
    for(int i = 0;i<N;i++){
        graph.push_back(vector<int>(N, 0));
    }
    for(int i = 0;i<N-1;i++){
        int a = A[i];
        int b = B[i];
        // 初始化邻接矩阵和入度数组
        graph[a][b] = 1;
        graph[b][a] = 1;

        degree[a] += 1;
        degree[b] += 1;
    }
    while(!isTrue(degree, N)){
        // 查找入度为1的节点
        for(int i = 1;i<N;i++){
            if(degree[i]==1){
                // 查找与i相连接的节点
                for(int k = 0;k<N;k++){
                    if(graph[i][k] == 1){
                        int _c = count[i] / cap + (count[i] % cap>0?1:0);
                        fule += _c;
                        count[k]+=count[i];
                        count[i] = 0;
                        degree[k]--;
                        degree[i]--;
                        graph[i][k] = 0;
                        graph[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
    return fule;
}


int main() {

    vector<int> A = {1,1,1,9,9,9,9,7,8};
    vector<int> B = {2,0,3,1,6,5,4,0,0};

    vector<int> A1 = {0,1,1};
    vector<int> B1 = {1,2,3};
    cout<<solution(A, B)<<endl;
    return 0;
}
