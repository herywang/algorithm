//
// Created by wangheng on 2022/7/15.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0){
            return false;
        }
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
            if(s.size() > k){
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {4,1,2,3,1,2,3};
    cout<<s->containsNearbyDuplicate(nums, 2)<<endl;
    return 0;
}
