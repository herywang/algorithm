/**
 * @file solution7.cpp
 * @author your name (you@domain.com)
 * @brief 整数反转
 * @version 0.1
 * @date 2022-08-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
};

int main() {
    auto s = new Solution;
    cout << s->reverse(-123456) << endl;
    delete s;
    return 0;
}