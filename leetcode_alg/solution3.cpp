//
// Created by wangheng on 2022/6/13.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int tmp[26] = {-1};
    memset(tmp, -1, 26 * sizeof(int));
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int tmpLen = 0;
    for (; right < s.length(); right++) {
        if (tmp[s[right] - 'a'] != -1) {
            // 第一次出现过, 左指针移动到第一次出现的位置+1
            int newleft = tmp[s[right]-'a'] + 1;
            for(int i = left;i<newleft;i++){
                tmp[s[i]-'a'] = -1;
            }
            left = newleft;
            maxLen = max(maxLen, tmpLen);
            tmpLen = right - left + 1;
            // 重置重复出现过的字符第一次出现位置
            tmp[s[right]-'a'] = right;
        } else {
            // 字串中没有出现过，记录当前字符第一次出现的位置
            tmp[s[right]-'a'] = right;
            tmpLen++;
            maxLen = max(maxLen, tmpLen);
        }
    }
    return maxLen;
}

int main() {
    int res = lengthOfLongestSubstring("abcaddceftggre");
    std::cout << res << std::endl;
    return 0;
}
