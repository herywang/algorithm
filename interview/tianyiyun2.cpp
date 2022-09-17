#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    string str;
    cin >> str;
    string _tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ',') {
            _tmp.push_back(str[i]);
        } else {
            if (!_tmp.empty()) {
                nums.push_back(atoi(_tmp.c_str()));
                _tmp.erase(0, _tmp.size());
            }
        }
    }
    if (!_tmp.empty()) {
        nums.push_back(atoi(_tmp.c_str()));
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            ans.emplace_back(nums[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 != 0) {
            ans.emplace_back(nums[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << ans[i] << ",";
        } else {
            cout << ans[i] << endl;
        }
    }
    return 0;
}