/**
 * @file solution91.cpp
 * @author your name (you@domain.com)
 * @brief 解码方法
 * @version 0.1
 * @date 2022-08-31
 * 动态规划
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        if (N == 0) {
            throw "string size can not be 0";
        }
        if (N < 2) {
            return s[0] == '0' ? 0 : 1;
        }
        vector<int> dp(N + 1);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0 : 1);
        for (int i = 1; i < N; i++) {
            // 解码一个字符
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
            // 解码两个字符
            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[N];
    }
};

int main() {
    try {
        Solution *s = new Solution;
        string str = "";
        cout << s->numDecodings(str) << endl;
        delete s;
    } catch (char const *msg) {
        cerr << msg << endl;
    }
    return 0;
}