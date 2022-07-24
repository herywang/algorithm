//
// Created by wangheng on 2021/6/21.
// 括号生成算法
#include "iostream"
#include "vector"

using namespace std;

/**
 * 方法1：回溯法
 */
class Solution1 {
private:
    void backtrack(vector<string> &res, string &current, int left, int right, int &n) {
        if (current.size() == n * 2) {
            res.push_back(current);
            return;
        }
        if (left < n) {
            current.push_back('(');
            backtrack(res, current, left + 1, right, n);
            current.pop_back();
        }
        if (right < left) {
            current.push_back(')');
            backtrack(res, current, left, right + 1, n);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

/**
 * 方法②：
 * @return
 */

int main() {
    auto s1 = new Solution1;
    auto vector1 = s1->generateParenthesis(3);
    for (string s:vector1) {
        cout << s << " | ";
    }
    cout << endl;

    return 0;
}

