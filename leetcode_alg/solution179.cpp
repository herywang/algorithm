/**
 * @file solution179.cpp
 * @author your name (you@domain.com)
 * @brief 最大数
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
private:
    int static comp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for (int &v : nums) {
            if (ans == "" && v == 0) {
                continue;
            }
            ans.append(to_string(v));
        }
        if (ans == "") {
            return "0";
        }
        return ans;
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {3, 30, 34, 5, 9};
    s->largestNumber(nums);
    delete s;
    return 0;
}
