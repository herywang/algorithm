/**
 * @file solution347.cpp
 * @author your name (you@domain.com)
 * @brief 前k个高频元素
 * @version 0.1
 * @date 2022-09-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> _map;
    // 计数,统计数量
    for (int &n : nums) {
        if (_map.count(n)) {
            _map[n] += 1;
        } else {
            _map[n] = 1;
        }
    }
    auto compareFunc = [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    };

    vector<pair<int, int>> container;
    for (auto &p : _map) {
        container.push_back(p);
        push_heap(container.begin(), container.end(), compareFunc);
    }
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(container[0].first);
        pop_heap(container.begin(), container.end(), compareFunc);
        container.pop_back();
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 4};
    vector<int> ans = topKFrequent(nums, 2);
    for (auto &n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}