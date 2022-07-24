//
// Created by wangheng on 2022/6/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int maximumGap = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1;i<nums.size();i++){
            maximumGap = max(nums[i]-nums[i-1], maximumGap);
        }
        return maximumGap;
    }
};

int main() {
    vector<int> num = {3,2,4,5,8,2,1};
    auto p = new Solution();
    cout<<"maximum gap is:"<<p->maximumGap(num);
    return 0;
}
