/**
 * @file netease_f1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int _t;
        cin >> _t;
        nums.push_back(_t);
    }
    sort(nums.begin(), nums.end());
    int ans = 0xFFFFFF;
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] < ans) {
            ans = nums[i] - nums[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}