//
// Created by wangheng on 2022/7/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid_l = 0, mid_r = nums.size();
        if(nums.size() == 0){
            return false;
        }else if(nums.size()== 1){
            return nums[0] == target;
        }
        // 找到中间分界点
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                mid_l = i-1;
                mid_r = i;
                break;
            }
        }


    }
};

int main() {

    return 0;
}
