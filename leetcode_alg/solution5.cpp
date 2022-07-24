//
// Created by wangheng on 2022/7/16.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 解法1：中心扩散法求解最长回文字串
 */
class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int maxLen = 1;
        int start = 0;
        int left = 0, right = 0;
        int tmpLen;
        for (int i = 0; i < s.length(); i++) {
            tmpLen = 1;
            left = i - 1;
            right = i + 1;
            while (left >= 0 && s[left] == s[i]) {
                left--;
                tmpLen++;
            }
            while (right < s.length() && s[right] == s[i]) {
                right++;
                tmpLen++;
            }
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                tmpLen += 2;
                left--;
                right++;
            }
            if (tmpLen > maxLen) {
                maxLen = tmpLen;
                start = left + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

/**
 * 解法2：动态规划算法
 */
class Solution2 {
public:
    string longestPalindrome(string s) {
        const int len = s.length();
        bool dp[len][len];
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < len; i++) {
            memset(dp[i], false, sizeof(bool) * len);
        }
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // s[i]字符和s[j]字符相等
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    auto s = new Solution2;
    cout << s->longestPalindrome("babaddab") << endl;
    return 0;
}
