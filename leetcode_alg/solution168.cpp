/**
 * @file solution168.cpp
 * @author your name (you@domain.com)
 * @brief Excel表列名称 (10进制转26进制)
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;
            ans += (char)(columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
}