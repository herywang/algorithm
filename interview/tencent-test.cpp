/**
 * @file tencent-test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-29
 *
 * 给定一个只包含 "()[]{}" 六种字符的字符串。规定它们的优先级由外至内为："{}", "[]", "()"，同一级的可以嵌套，并列。
 * 要求判断给定的字符串是否是合法的括号字串？
例："()", "{((()())())[()]}()" 是合法的。"())", "([])", "())(()" 都是不合法的。
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string &str) {
    stack<char> _s;
    // 定义一个map, 用于设置每个括号的优先级,
    unordered_map<char, int> _m;
    _m['{'] = 3;
    _m['['] = 2;
    _m['('] = 1;
    _m['}'] = 3;
    _m[']'] = 2;
    _m[')'] = 1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            int prio = _m[str[i]]; // 获取当前括号的优先级
            if (!_s.empty()) {
                if (prio > _m[_s.top()]) {
                    return false;
                } else {
                    _s.push(str[i]);
                }
                continue;
            }
            _s.push(str[i]);
        } else {
            // 当前字符为: ), ], }这三种, 需要弹出栈顶元素
            if (_s.empty()) {
                return false;
            }
            int p = _m[_s.top()];
            if (p != _m[str[i]]) {
                return false;
            }
            _s.pop();
        }
    }
    if (_s.empty()) {
        return true;
    }
    return false;
}

int main() {
    string str1 = "()";
    string str2 = "{((()())())[()]}()";
    string str3 = "())";
    bool ans = isValid(str3);
    cout << ans << endl;
    return 0;
}