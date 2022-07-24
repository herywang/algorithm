//
// Created by wangheng on 2022/7/19.
// 原地排序

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        auto v = vector<int>(3, 0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]] ++;
        }
        int p = 0;
        int i = 0;
        while(i<nums.size()){
            if(v[p] > 0){
                nums[i] = p;
                v[p]--;
                i++;
            }else{
                p++;
            }
        }
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {1,2,0,0,1,2,1,1};
    s->sortColors(nums);
    for(int i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    testSolution();
    return 0;
}
