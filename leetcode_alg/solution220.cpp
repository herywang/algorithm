//
// Created by wangheng on 2022/7/15.
// 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
//
//如果存在则返回 true，不存在返回 false。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() == 0) {
            return false;
        }
        set<int> slidWindow;
        for (int i = 0; i < nums.size(); i++) {
            // 满足窗口长度 <= k
            // 遍历窗口中的元素，看是否存在abs(nums[i] - tmp)值 <= t
            // 查找比nums[i] - t 大的最小值
            auto iterator = slidWindow.lower_bound(nums[i] - t);
            if (iterator != slidWindow.end() && *iterator <= (nums[i] + t)) {
                return true;
            }
            slidWindow.insert(nums[i]);
            if (slidWindow.size() >= k) {
                slidWindow.erase(nums[i - k]);
            }
        }
        return false;
    }

};

void testSetLowerBound() {
    set<int> s;
    s.insert(1);
    s.insert(8);
    s.insert(6);
    s.insert(4);
    s.insert(4);

    for (auto t = s.begin(); t != s.end(); t++) {
        cout << *t << endl;
    }
    cout << "=======" << endl;
    auto t = s.lower_bound(7);
    cout << (t == s.end()) << endl;
    cout << *t << endl;
    cout << "=======" << endl;
    t = s.upper_bound(7);
    cout << (t == s.end()) << endl;
    cout << *t << endl;
}
int main() {
//    auto s = new Solution;
//    vector<int> nums = {1, 5, 9, 1, 5, 9};
//    vector<int> nums = {1, 2, 3, 1};
//    vector<int> nums = {-2147483648, 2147483647};
//    cout << s->containsNearbyAlmostDuplicate(nums, 1, 1) << endl;
    testSetLowerBound();

    return 0;
}
