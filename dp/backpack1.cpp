//
// Created by wangheng on 2022/8/22.
// 01背包问题：空间复杂度优化到O(c), c为背包总容量

#include <iostream>

using namespace std;

/**
 * @param n 物品数量
 * @param m 背包总容量
 * @param weights 物品重量数组
 * @param values 物品价值数组
 * @return 最大价值
 */
int solution(int n, int m, int *weights, int *values) {
    int f[m + 1];
    memset(f, 0, sizeof(int) * (m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= weights[i]; j--) {
            f[j] = max(f[j], f[j - weights[i]] + values[i]);
        }
    }
    return f[m];
}

int main(int argc, char *argv[]) {
    int n, m;// 物品数量，背包体积
    cin >> n >> m;
    int *weights = new int[n];
    int *values = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << solution(n, m, weights, values) << endl;
    return 0;
}