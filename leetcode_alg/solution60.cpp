//
// Created by wangheng on 2022/7/25.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        if (n < 1 || n > 9 || k < 1) {
            return res;
        }
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        vector<bool> isVisited(n, false);
        vector<int> path;
        int count = 0;
        dfs(nums, isVisited, path, k, res, count);
        return res;
    }

    /**
     * @param nums 输入的数组
     * @param isVisited 是否被访问过
     * @param path 排序路径
     * @param k 第k个排序
     */
    void dfs(vector<int> &nums, vector<bool> &isVisited, vector<int> &path, int k, string &resStr, int &count) {
        if (resStr != "") {
            return;
        }
        if (path.size() == nums.size()) {
            // 完成一个排列
            count += 1;
            if (count == k) {
                resStr = toString(path);
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (isVisited[i]) {
                continue;
            }
            isVisited[i] = true;
            path.emplace_back(nums[i]);
            dfs(nums, isVisited, path, k, resStr, count);
            path.pop_back();
            isVisited[i] = false;
        }
    }

    string toString(vector<int> &nums) {
        stringstream ss;
        for (int i: nums) {
            ss << i;
        }
        return ss.str();
    }
};

void testSolution() {
    auto s = new Solution;
    const string &res = s->getPermutation(4, 9);
    cout << res << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
