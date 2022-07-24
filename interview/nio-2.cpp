//
// Created by wangheng on 2022/7/17.
//

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    int nixvshuCount(vector<int> &nums){

    }
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }

    int permute(int n, int k) {
        vector<int> nums;
        for(int i = 0;i<n;i++){
            nums.push_back(i+1);
        }
        vector<vector<int> > res;
        int ans = 0;
        backtrack(res, nums, 0, (int)nums.size());

        // 全排列完成，开始搜索逆序对
        for (int i = 0; i < res.size(); i++) {
            vector<int> integers = res[i];
            print_vec(integers);
            int t = 0;
            for (int j = 0; j < integers.size() - 1; j++) {
                for(int c = j+1;c<integers.size();c++){
                    if (integers[j] > integers[c]) {
                        t++;
                    }
                }
            }
            cout<<"逆序对个数:"<<t<<endl;
            if (t <= k) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    auto s = new Solution;
    int n, k;
    cin>>n>>k;

    int ans = s->permute(n, k);
    cout<<ans % (1000000000+7)<<endl;
    return 0;
}
