#include <iostream>
#include <vector>

using namespace std;

int solve(vector<long long> &nums, int n, int k) {
    long i = 0;
    int t = 0;
    int res = 0;
    while (i < k) {
        if (nums[t] > 0) {
            nums[t]--;
            res = t;
            i++;
        }
        t++;
        t %= n;
    }
    return res + 1;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        long long _num;
        cin >> _num;
        nums.push_back(_num);
    }
    return 0;
}