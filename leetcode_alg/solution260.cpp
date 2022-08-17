//
// Created by wangheng on 2022/8/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int n:nums){
            map[n] += 1;
        }
        for(auto m:map){
            if(m.second == 1){
                res.emplace_back(m.first);
            }
            if(res.size()==2){
                return res;
            }
        }
        return res;
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {1,2,1,3,2,5};
    const vector<int> &res = s->singleNumber(nums);
    for(int _s:res){
        cout<<_s<<" ";
    }
    cout<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
