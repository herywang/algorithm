//
// Created by wangheng on 2021/6/22.
// 将所有的0移动到末尾,并保持原有数组顺序不变

#include <iostream>
#include <vector>
#include "vec_util.h"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<2){
            return;
        }else{
            int i = 0;
            int j = 0;
            while(j<nums.size() && i<nums.size()){
                // 找到第一个为0的数
                while(nums[i] != 0 && i < nums.size())
                    i++;
                if(i == nums.size())
                    break;
                // 第二个指针指向一个不为0的数
                j = i+1;
                while(nums[j]==0 && j<nums.size())
                    j++;
                if(j == nums.size())
                    break;
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
        }
    }

    //方法二
    void moveZeroes2(vector<int>& nums){
        if(nums.size()<2){
            return;
        }
        int index = 0;
        for(int j = 0;j<nums.size();j++){
            if(nums[j] != 0){
                nums[index] = nums[j];
                index++;
            }
        }
        for(int i = index;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};

int main() {

    vector<int> vec = {1,2,3,4,5,9,0,3,9,2,1,0,0};
    Solution* s = new Solution;
    s->moveZeroes2(vec);
    print_vec(vec);
    return 0;
}
