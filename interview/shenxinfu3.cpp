#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    char last = '0';
    int ans = 0;
    string tmp;
    int maxLen = 0;
    // 计算最长连续1子串长度
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            tmp.push_back('1');
        } else {
            if (tmp.length() > 0) {
                maxLen = maxLen > tmp.length() ? maxLen : tmp.length();
            }
            tmp = "";
        }
    }
    tmp = "";
    string rr;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            if (tmp.length() == maxLen) {
                rr.push_back('a');
                rr.push_back('0');
                tmp = "";
            } else {
                rr = rr + tmp + "0";
                tmp = "";
            }
        } else {
            tmp.push_back('1');
        }
    }

    set<string> s;
    for (int i = 0; i < rr.length() - 1; i++) {
        for (int j = i + 1; j <= rr.length(); j++) {
            string subStr = rr.substr(i, j - i);
            if (subStr.find("a") != subStr.npos) {
                s.insert(subStr);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}