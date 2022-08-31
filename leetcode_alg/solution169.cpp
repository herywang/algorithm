/**
 * @file solution169.cpp
 * @author your name (you@domain.com)
 * @brief 寻找多数元素
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> _map;
        for (auto &n : nums) {
            if (!_map.count(n)) {
                _map[n] = 1;
            } else {
                _map[n] += 1;
            }
            if (_map[n] > nums.size() / 2) {
                return n;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}