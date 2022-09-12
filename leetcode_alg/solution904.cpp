/**
 * @file solution904.cpp
 * @author your name (you@domain.com)
 * @brief 水果成蓝
 * @version 0.1
 * @date 2022-09-05
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
    int totalFruit(vector<int> &fruits) {
        // 篮子
        unordered_map<int, int> basket;
        int left = 0;
        int len = 0;
        int ans = 0;
        for (int i = 0; i < fruits.size(); i++) {
            basket[fruits[i]]++;
            len++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
                len--;
            }
            if (len > ans) {
                ans = len;
            }
        }
        return ans;
    }
};

int main() {
    auto s = new Solution;
    vector<int> fruits = {0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 1, 3, 4};
    cout << s->totalFruit(fruits) << endl;
    delete s;
    return 0;
}