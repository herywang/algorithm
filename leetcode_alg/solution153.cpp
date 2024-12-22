//
// Created by wangheng on 1/10/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // 中间值大于右边值，最小值在右边，收缩左边界
                left = mid + 1;
            } else {
                // 中间值小于右边值，最小值在左边，收缩右边界
                right = mid;
            }
        }
        return nums[left];
    }
};

int main(int argc, char *argv[]) {
    auto s = new Solution;
    vector<int> nums{5, 1, 2, 3, 4};
    cout << "结果是:" << s->findMin(nums) << endl;
    delete s;
    return 0;
}