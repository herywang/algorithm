//
// Created by wangheng on 2022/6/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0xFF;
        for(int i = left;i<=right;i++){
            res = res & i;
        }
        return res;
    }
};

int main() {
    Solution* s = new Solution;
    int res = s->rangeBitwiseAnd(2147483646,2147483647);
    cout<<res<<endl;
    return 0;
}
