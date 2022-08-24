//
// Created by wangheng on 2022/8/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    // 树适合种植的位置
    int position;
    // 树的生长半径
    int space;
    // 树产生的价值
    int value;
};

class Solution {
public:
    int solution(int N, vector<Tree> &trees) {
        int maxPosition = trees[N-1].position;
        int dp[maxPosition+1];
        memset(dp, 0, sizeof(int)*(maxPosition+1));
    }
};

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    vector<Tree> trees;
    for (int i = 0; i < N; i++) {
        Tree t;
        cin >> t.position;
        trees.emplace_back(t);
    }
    for (int i = 0; i < N; i++) {
        Tree &t = trees[i];
        cin >> t.space;
    }
    for (int i = 0; i < N; i++) {
        Tree &t = trees[i];
        cin >> t.value;
    }
    sort(trees.begin(), trees.end(), [](Tree t1, Tree t2) {
        return t1.position > t2.position;
    });

    auto s = new Solution;
    cout << s->solution(N, trees) << endl;
    delete s;
    return 0;
}