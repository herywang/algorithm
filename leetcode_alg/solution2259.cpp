//
// Created by wangheng on 2022/8/25.
// 移除指定数字

#include <iostream>

using namespace std;

class Solution {
public:
    // method 1
    string removeDigit(string number, char digit) {
        string ans = "";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                string _s = number.substr(0, i);
                _s.append(number.substr(i + 1, number.size() - i - 1));
                ans = max(_s, ans);
            }
        }
        return ans;
    }

    // method 2
    string removeDigit1(string number, char digit) {
        string ans;
        int latestIndex = 0;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                if (i + 1 < number.size() - 1 && number[i + 1] > number[i]) {
                    ans = number.substr(0, i);
                    ans.append(number.substr(i + 1, number.size() - i - 1));
                    return ans;
                } else {
                    latestIndex = i;
                }
            }
        }
        ans = number.substr(0, latestIndex);
        ans.append(number.substr(latestIndex + 1, number.size() - latestIndex - 1));
        return ans;
    }


};

void testSolution() {
    auto s = new Solution;
    cout << s->removeDigit1("223221", '2') << endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}