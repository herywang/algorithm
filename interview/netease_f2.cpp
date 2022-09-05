/**
 * @file netease_f2.cpp
 * @author your name (you@domain.com)
 * @brief 差分数组
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    vector<int> subA;
    vector<int> subB;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    // 计算差分数组
    for (int i = 1; i < n; i++) {
        subA.push_back(a[i] - a[i - 1]);
        subB.push_back(b[i] - b[i - 1]);
    }
    int ans = -1;
    int l = 0;
    int r = 0;
    while (r < n) {
        if (subA[r] == subB[r]) {
            r++;
        } else {
            ans = r - l + 1;
            l = r + 1;
            r = r + 1;
        }
    }
    if (ans == -1) {
        ans = r - l + 1;
    }
    cout << ans << endl;
    delete[] a;
    delete[] b;
    return 0;
}