//
// Created by wangheng on 2021/6/24.
// 验证回文串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLetter(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9'));
    }

    bool isPalindrome(string s) {
        if (s.size() < 1)
            return true;
        // 双指针解决
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            while(i<j && !isLetter(s[i]))
                i++;
            while(i<j && !isLetter(s[j]))
                j--;
            // 大写转小写
            if(s[i] < 'a'){
                s[i] += 32;
            }
            if(s[j] < 'a'){
                s[j] += 32;
            }
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
//    string str = "A man, a plan, a canal: Panama";
//    string str = "race a car";
    string str = "0P";
    Solution *solution = new Solution;
    cout<<solution->isPalindrome(str)<<endl;
    return 0;
}
