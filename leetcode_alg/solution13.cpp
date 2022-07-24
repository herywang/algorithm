//
// Created by wangheng on 2021/6/18.
// 罗马数字转整数
#include "iostream"
#include "map"

using namespace std;


class Solution {
private:
    map<string, int> value = {
            {"M",  1000},
            {"CM", 900},
            {"D",  500},
            {"CD", 400},
            {"C",  100},
            {"XC", 90},
            {"L",  50},
            {"XL", 40},
            {"X",  10},
            {"IX", 9},
            {"V",  5},
            {"IV", 4},
            {"I",  1},
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'X': {
                    if (i < s.length() - 1 && s[i + 1] == 'C') {
                        ans += (value.find("XC"))->second;
                        i += 1;
                    }else if(i < s.length() - 1 && s[i + 1] == 'L'){
                        ans += (value.find("XL"))->second;
                        i += 1;
                    } else {
                        ans += (value.find("X"))->second;
                    }
                    break;
                }
                case 'I': {
                    if (i < s.length() - 1 && s[i + 1] == 'X') {
                        ans += (value.find("IX"))->second;
                        i += 1;
                    } else if (i < s.length() - 1 && s[i + 1] == 'V') {
                        ans += (value.find("IV"))->second;
                        i += 1;
                    } else {
                        ans += (value.find("I"))->second;
                    }
                    break;
                }
                case 'C': {
                    if (i < s.length() - 1 && s[i + 1] == 'D') {
                        ans += value.find("CD")->second;
                        i += 1;
                    } else if(i < s.length() - 1 && s[i + 1] == 'M'){
                        ans += value.find("CM")->second;
                        i += 1;
                    }else {
                        ans += value.find("C")->second;
                    }
                    break;
                }
                default: {
                    string key(1, s[i]);
                    ans += value.find(key)->second;
                }
            }
        }
        return ans;
    }
};

int main() {
    auto solution = new Solution;
    int ans = solution->romanToInt("MMMXLV");
    cout << ans << endl;
    return 0;
}
