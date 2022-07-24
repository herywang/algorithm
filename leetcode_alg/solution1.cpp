//
// Created by wangheng on 2022/7/14.
// 两数之和

#include <iostream>
#include <vector>
#include <map>
#include "../include/vec_util.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        if (nums.size() < 2) {
            return res;
        }
        map<int, int> m;
        int a;
        for (int i = 0; i < nums.size(); i++) {
            a = target - nums[i];
            auto it = m.find(a);
            if(it != m.end()){
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }else{
                m.insert({nums[i], i});
            }
        }
        return res;
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {2,7,11,15};
    vector<int> res = s->twoSum(nums, 58);
    print_vec(res);
    return 0;
}
