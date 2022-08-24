//
// Created by wangheng on 2022/7/7.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * @param num 物品数量
 * @param weights 重量
 * @param values 价值
 * @param capacity 背包剩余容积
 * @return 能装的最大价值
 */
int maxValues(int num, int *weights, int *values, int capacity) {
    int dp[num + 1][capacity + 1];
    // 数组置0
    for (int i = 0; i < num + 1; i++) {
        memset(dp[i], 0, sizeof(int) * (capacity + 1));
    }
    // f[i][v]: 前i件物品放到容量为v的背包中能够产生的最大价值
    for (int i = 1; i <= num; i++) {
        for (int v = 1; v <= capacity; v++) {
            if (v - weights[i-1] >= 0) {
                // 容量v放得下values[i]物品
                dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - weights[i - 1]] + values[i - 1]);
            } else {
                // 放不下
                dp[i][v] = dp[i - 1][v];
            }
        }
    }
    return dp[num][capacity];
}

int main() {
    int num = 0;
    int capacity = 0;
    cout << "请输入物品数量" << endl;
    cin >> num;
    cout << "请输入背包容积" << endl;
    cin >> capacity;
    cout << "请输入每个物品的重量" << endl;
    int *weights = new int[num];
    int *values = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> weights[i];
    }
    cout << "请输入每个物品的价值" << endl;
    for (int i = 0; i < num; i++) {
        cin >> values[i];
    }

    cout << "能放入的最大价值为：" << endl;
    cout << maxValues(num, weights, values, capacity) << endl;
    return 0;
}
