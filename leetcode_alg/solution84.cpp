//
// Created by wangheng on 2022/8/7.
// 柱状图中的最大矩形面积

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0) {
            return 0;
        }
        if (heights.size() == 1) {
            return heights[0];
        }
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        vector<int> stack = {0};
        int ans = 0;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            // 当前元素比栈顶元素小
            while (heights[i] < heights[stack.back()]) {
                int currentHeight = heights[stack.back()];
                stack.pop_back();

                int currentWidth = i - stack.back() - 1;
                ans = max(ans, currentHeight * currentWidth);
            }
            stack.emplace_back(i);
        }
        return ans;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {2, 1, 2};
    vector<int> heights3 = {4, 2, 0, 3, 2, 5};
    cout << s->largestRectangleArea(heights) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
