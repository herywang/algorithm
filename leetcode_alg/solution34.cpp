//
// Created by wangheng on 2021/7/4.
// 在排好序的数据中查找第一个和最后一个出现的位置

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans = {-1, -1};
        if (nums.size() == 0) {
            return ans;
        }
        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans[0] = i;
                ans[1] = i;
                break;
            }
        }
        if (ans[0] != -1) {
            for (i = i + 1; i < nums.size(); i++) {
                if (nums[i] > target) {
                    return ans;
                } else {
                    // 等于target
                    ans[1] = i;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
private:
    // 计算下边界
    int lowerBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == nums[mid]) {
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    // 计算上边界
    int upperBound(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if(target >= nums[mid]){
                l = mid+1;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        if(lower<= upper){
            ans.emplace_back(lower);
            ans.emplace_back(upper);
        }else{
            ans.emplace_back(-1);
            ans.emplace_back(-1);
        }
        return ans;
    }
};

void testSolution2() {
    auto s = new Solution2;
    vector<int> nums = {5,7,7,8,8,10};
    auto v = s->searchRange(nums, 6);
    cout<<v[0]<<"-"<<v[1]<<endl;
    delete s;
}

int main() {
    testSolution2();
}
