//
// Created by wangheng on 2021/7/1.
// 搜索旋转排序树组

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() < 2) {
            return nums[0] == target ? 0 : -1;
        }
        int k = -1;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] < nums[i - 1]) {
                k = i;
                break;
            }
            i++;
        }
        // [0, i)升序,[i, end)升序, 并且nums[0] > nums[end-1]
        int l;
        int r;
        int mid;
        if (k == -1) {
            l = 0;
            r = nums.size();
        } else if (target <= nums[nums.size() - 1]) {
            // target 在右半部分
            l = k;
            r = nums.size();
        } else {
            // target 在左半部分
            l = 0;
            r = k;
        }
        while (l < r) {
            mid = (l + r) >> 1;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution *solution = new Solution;
    //    vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums = {1, 3};
    int target = 3;
    cout << solution->search(nums, target) << endl;
    delete solution;
    return 0;
}
