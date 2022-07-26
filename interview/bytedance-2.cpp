//
// Created by wangheng on 2022/7/26.
//

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void dfs(vector<int> &nums, vector<int> &path, int D, int &res, int begin) {
    if (path.size() == 3) {
        res += 1;
        return;
    }
    for (int i = begin; i < nums.size(); i++) {
        if (path.size() > 0 && abs(path[0] - nums[i]) > D) {
            break;
        }
        path.emplace_back(nums[i]);
        dfs(nums, path, D, res, i + 1);
        path.pop_back();
    }
}
int solution(vector<int> &nums, int D) {
    vector<int> path;
    int ans = 0;
    if (nums.size() < 1 || nums.size() > 1000000 || D < 1 || D > 1000000) {
        return ans;
    }
    dfs(nums, path, D, ans, 0);
    return ans;
}


void testSolution() {
    int N, D;
    cin >> N >> D;
    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int _t;
        cin >> _t;
        nums.push_back(_t);
    }
    int startTime, endTime;
    startTime = clock();
    cout << solution(nums, D) << endl;
    endTime = clock();
    cout << "耗时: " << (endTime - startTime) << "毫秒" << endl;
}

int main() {
    testSolution();
    return 0;
}
