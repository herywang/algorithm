//
// Created by wangheng on 2022/7/24.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.size() == 0) {
            return res;
        }
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int l = 0, r = 1;
        while (r < nums.size()) {
            long _res = long(nums[r]) - long(nums[l]);
            if (_res == (long)(r - l)) {
                r++;
                continue;
            }
            stringstream ss;
            if (r - l > 1) {
                ss << nums[l];
                ss << "->";
                ss << nums[r - 1];
                res.push_back(ss.str());
            } else {
                res.push_back(to_string(nums[l]));
            }
            l = r;
            r++;
        }
        stringstream ss;
        if (r - l > 1) {
            ss << nums[l];
            ss << "->";
            ss << nums[r - 1];
            res.push_back(ss.str());
        } else {
            res.push_back(to_string(nums[l]));
        }
        return res;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<int> nums3 = {-2147483648,-2147483647,2147483647};
    const vector<string> &ranges = s->summaryRanges(nums3);
    for (string s: ranges) {
        cout << s << endl;
    }
    delete s;
}

int main() {
    testSolution();
    return 0;
}
