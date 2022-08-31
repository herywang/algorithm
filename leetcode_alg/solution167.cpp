/**
 * @file solution167.cpp
 * @author your name (you@domain.com)
 * @brief 有序数组两数之和
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ans(2);
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                return ans;
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    auto s = new Solution;
    vector<int> numbers = {2, 7, 11, 15};
    auto ans = s->twoSum(numbers, 9);
    cout << ans[0] << "-" << ans[1] << endl;
    delete s;
    return 0;
}