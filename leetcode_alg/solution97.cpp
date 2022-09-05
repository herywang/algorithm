/**
 * @file solution97.cpp
 * @author your name (you@domain.com)
 * @brief 交错字符串
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        uint32_t len1 = s1.length();
        uint32_t len2 = s2.length();
        bool dp[len1 + 1][len2 + 1];
        dp[0][0] = true;
        // dp[i][j]表示s1的前i个字符和s2的前j个字符, 能否组成s3的前i+j个字符
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = (dp[i - 1][0] && s1[i - 1] == s3[i - 1]);
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = (dp[0][j - 1] && s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) or (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    auto s = new Solution;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << s->isInterleave(s1, s2, s3) << endl;

    delete s;
    return 0;
}