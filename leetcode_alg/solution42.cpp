//
// Created by wangheng on 2022/7/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int res = 0;
        if (n <= 1) {
            return res;
        }
        // 从左往右最大高度
        vector<int> left_to_right_max(n, 0);
        // 从右往左最大高度
        vector<int> right_to_left_max(n, 0);

        left_to_right_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_to_right_max[i] = max(left_to_right_max[i - 1], height[i]);
        }
        right_to_left_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_to_left_max[i] = max(right_to_left_max[i + 1], height[i]);
        }

        for (int i = 1; i < n; i++) {
            int t = min(left_to_right_max[i], right_to_left_max[i]) - height[i];
            res += (t > 0 ? t : 0);
        }
        return res;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s->trap(height) << endl;
    delete s;
}
int main() {
    testSolution();
    return 0;
}
