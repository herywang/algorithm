//
// Created by wangheng on 2021/6/24.
// 字符串转整数

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class Solution {
public:
    bool isCharacter(char &c) {
        return (c == '-' || c == '+');
    }

    bool isDigit(char &c) {
        return (c >= '0' && c <= '9');
    }

    bool isBackSpace(char& c){
        return c==' ';
    }

    int myAtoi(string s) {
        vector<char> numbers;
        if (s.length() < 1) {
            return 0;
        }
        for (int i = 0; i < s.size(); i++) {
            if(isBackSpace(s[i])){
                if(numbers.empty())
                    continue;
                else
                    break;
            }
            if (!isCharacter(s[i]) && !isDigit(s[i])) {
                break;
            } else {
                if (isCharacter(s[i])) {
                    if (numbers.empty()) {
                        numbers.push_back(s[i]);
                    } else {
                        break;
                    }
                } else {
                    numbers.push_back(s[i]);
                }
            }
        }
        if(numbers.empty())
            return 0;
        bool isMinus;
        int start;
        if (isCharacter(numbers[0])) {
            if (numbers.size() < 2)
                return 0;
            else {
                isMinus = numbers[0] == '-';
                start = 1;
            }
        } else {
            isMinus = false;
            start = 0;
        }
        long ans = 0;
        int j = 0;
        long min = -2147483648;
        long max = 2147483647;
        for (int i = numbers.size() - 1; i >= start; i--) {
            if(numbers[i] != '0' && j>10)
                return isMinus?min:max;
            ans += (((int)(numbers[i] - '0')) * pow(10, j));
            j++;
        }

        if (isMinus){
            ans = -ans;
            if(ans < min)
                return min;
            return ans;
        }else{
            if(ans > max){
                return max;
            }
            return ans;
        }
    }
};

int main() {
//    string s = "words and 987";
//    string s = "  -98 7 wordss";
//    string s = "42";
//    string s = "200000000000000000000000";
    string s = "  0000000000012345678";

//    string s = "   -42";

    Solution* solution = new Solution;
    cout<<solution->myAtoi(s)<<endl;
//    cout<<(1<<31)<<endl;

    return 0;
}
