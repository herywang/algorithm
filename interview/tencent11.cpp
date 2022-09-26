//
// Created by wangheng on 2022/9/24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(vector<int> &numbers) {
    vector<vector<int>> ans;
    if (numbers.size() < 3) {
        return ans;
    }

    int left;
    int right;
    int mid;
    for (int i = 0; i < numbers.size() - 2; i++) {
        vector<int> path;
        left = i;
        right = numbers.size() - 1;
        mid = left + 1;
        while (mid < right) {
            int _v = numbers[left] + numbers[right] + numbers[mid];
            if (_v == 0) {
                path.emplace_back(left);
                path.emplace_back(mid);
                path.emplace_back(right);
                ans.emplace_back(path);
                path.erase(path.begin(), path.end());
                mid++;
            } else if (_v < 0) {
                mid++;
            } else {
                right--;
            }
        }
    }
    return ans;
}

int main() {
    // int a;
    // cin >> a;
    vector<int> numbers = {-3, -2, -1, 1, 2, 3, 4};
    vector<vector<int>> ans = solve(numbers);
    for (auto &vec : ans) {
        for (int n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << "Hello World!" << endl;
}