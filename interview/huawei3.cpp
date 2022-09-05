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
        // dp[i]表示种到第i颗数最大能产生的价值
        int dp[N + 1];
        dp[0] = 0;
        dp[1] = trees[0].value;
        for (int i = 1; i < N; i++) {
            // 如果当前数种下, 需要找到满足间隔之前的一棵树产生的价值
            int j = i - 1;
            for (; j >= 0; j--) {
                if (trees[i].position - trees[j].position >= (trees[i].space + trees[j].space)) {
                    // 满足间隔条件
                    break;
                }
            }
            int a = dp[j + 1] + trees[i].value;
            // 如果当前数不种, 则当前位置的最大价值等于前一个种下的树的最大价值
            int b = dp[i];
            dp[i + 1] = max(a, b);
        }
        return dp[N];
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
        return t1.position < t2.position;
    });

    auto s = new Solution;
    cout << s->solution(N, trees) << endl;
    delete s;
    return 0;
}