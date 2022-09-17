#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &nums, int M) {
    if (nums.size() < M) {
        return -1;
    }
    int left = 0;
    int right = M;
    while (right <= nums.size()) {
        // 1. 判断窗口内的数据最大值和最小值
        int _min = 0x7FFFFFF;
        int _min_index = -1;
        int _max = -1;
        for (int i = left; i < right; i++) {
            _max = max(nums[i], _max);
            if (nums[i] <= _min) {
                _min = nums[i];
                _min_index = i; // 最小值索引
                if (_min == 0) {
                    break;
                }
            }
        }
        if (_min == 0) {
            // 最小值等于0，说明窗口中包含0，则不能减小
            left = _min_index + 1;
            right = _min_index + 1 + M;
            if (right > nums.size()) {
                // 窗口越界
                break;
            }
        } else {
            for (int i = left; i < right; i++) {
                nums[i] = nums[i] - _min;
            }
            left = _min_index + 1;
            right = _min_index + 1 + M;
            if (right > nums.size()) {
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans += nums[i];
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int _t;
        cin >> _t;
        nums.push_back(_t);
    }
    cout << solve(nums, M) << endl;
}