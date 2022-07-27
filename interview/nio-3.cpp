//
// Created by wangheng on 2022/7/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int resolve(vector<vector<int>> &nums){
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> dp;
        for(int i = 0;i<n;i++){
            vector<int> row(m, 0);
            dp.push_back(row);
        }


    }


};

int main() {

    return 0;
}
