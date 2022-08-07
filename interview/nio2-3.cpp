#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    
    int _2index(vector<int> &path){
        int n = path.size();
        for(int i = 0;i<n;i++){
            if(path[i] == 2){
                return i;
            }
        }
        return 0;
    }

    int permute(int n, int k) {
        vector<int> nums;
        for(int i = 0;i<n;i++){
            nums.push_back(i+2);
        }
        vector<vector<int> > res;
        int ans = 0;
        backtrack(res, nums, 0, (int)nums.size());
        // 全排列完成，开始搜索逆序对
        for (int i = 0; i < res.size(); i++) {
            vector<int> integers = res[i];
            // 找出元素2的位置
            int i1 = _2index(integers);
            integers.insert(integers.begin()+i1, 1);
            int t = 0;
            int size = integers.size();
            for (int j = 0; j < size - 1; j++) {
                if (integers[j] > integers[j+1]) {
                    t++;
                }
            }
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
    // a1 < a2, 因此把a1, a2当成一个整体来看
    int ans = s->permute(n-1, k) % 1000000007;
    cout<<ans<<endl;
    return 0;
}