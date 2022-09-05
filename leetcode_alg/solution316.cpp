/**
 * @file solution316.cpp
 * @author your name (you@domain.com)
 * @brief 去除重复字符, 使得字典序最小
 * @version 0.1
 * @date 2022-09-04
 * 思路: 在考虑字符s[i]时, 如果存在单调栈中, 则不能加入进去, 直接count[s[i]]--;
 * 如果s[i]不存在单调栈中, 需要与栈顶元素比较, 如果栈顶元素比s[i]大, 并且后序的字符串中仍然包含栈顶元素,
 * 则需要将栈顶元素弹出.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.length() < 2) {
            return s;
        }
        string ans;
        string stack;
        // 记录字符串中每个字符的数量
        int *count = new int[26];
        // 记录栈中是否有这个字符
        int *visited = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        for (const char c : s) {
            if (!visited[c - 'a']) {
                // 如果栈中不存在当前字符, 需要将当前字符入栈
                // 首先循环弹出 s[i] > c
                while (!stack.empty() && stack.back() > c) {
                    if (count[stack.back() - 'a'] > 0) {
                        visited[stack.back() - 'a'] = 0;
                        stack.pop_back();
                    } else {
                        break;
                    }
                }
                visited[c - 'a'] = 1;
                stack.push_back(c);
            }
            count[c - 'a']--;
        }
        delete[] count;
        delete[] visited;
        return stack;
    }
};

int main() {
    auto s = new Solution;
    cout << s->removeDuplicateLetters("bcabc") << endl;
    delete s;
    return 0;
}