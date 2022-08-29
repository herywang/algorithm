#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> &graph, vector<int> &degree, int size_) {
    vector<pair<int, int>> ans;
    for (int i = 1; i < size_; i++) {
        // 查找入度为1的节点
        if (degree[i] >= 1) {
            for (int j = 1; j < size_; j++) {
                if (graph[i][j] == 1) {
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    ans.push_back(p);
                    degree[i] = 0;
                    degree[j] = 0;
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                    for (int k = 1; k < size_; k++) {
                        if (graph[j][k] == 1) {
                            graph[j][k] = 0;
                            graph[k][j] = 0;
                            degree[k]--;
                        }
                    }
                    for (int k = 1; k < size_; k++) {
                        if (graph[i][k] == 1) {
                            graph[i][k] = 0;
                            graph[k][i] = 0;
                            degree[k]--;
                        }
                    }
                }
            }
        }
    }
    return ans.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> _input;
    for (int i = 0; i < N - 1; i++) {
        int _t;
        cin >> _t;
        _input.emplace_back(_t);
    }
    // 构建无向图和入度矩阵
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
    vector<int> degree(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int _t = _input[i];
        graph[i + 1 + 1][_t] = 1;
        graph[_t][i + 2] = 1;
        degree[i + 2] += 1;
        degree[_t] += 1;
    }
    cout << solution(graph, degree, N + 1) << endl;
    return 0;
}