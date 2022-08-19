//
// Created by wangheng on 2022/8/18.
// 寻找重复数

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size() - 1;
        int size = (int) ceil(n / 32.);// 向上取整
        int *array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
        for (auto &_n: nums) {
            int t = _n / 32;
            if (array[t] & (1 << _n % 32)) {
                // 当前元素重复
                return _n;
            } else {
                array[t] |= 1 << _n % 32;
            }
        }
        return -1;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {3, 1, 3, 4};
    cout << s->findDuplicate(nums) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
