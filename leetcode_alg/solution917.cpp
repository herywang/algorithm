/**
 * @file solution917.cpp
 * @author your name (you@domain.com)
 * @brief 仅仅反转字母
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

string reverseOnlyLetters(string s) {
    if (s.length() <= 1) {
        return s;
    }
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        while (left < s.length() && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))) {
            left++;
        }
        while (right >= 0 && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))) {
            right--;
        }
        if (right < 0 || left >= s.length() || left >= right) {
            return s;
        }
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}

int main() {
    string s = "a-bC-dEf-ghIj";
    string s1 = "Test1ng-Leet=code-Q!";
    string s2 = "?6C40E";
    string ans = reverseOnlyLetters(s2);
    cout << ans << endl;
    return 0;
}