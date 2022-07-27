//
// Created by wangheng on 2022/7/26.
// 链接：https://www.nowcoder.com/questionTerminal/3a531996cc944a328ebc354749e96d27?page=1&onlyReference=false
//
//小红拿到了一个二进制字符串 sss，她可以删掉其中的一些字符，使得最终该字符串为一个2的幂（即可以表示为 2k2^k2k 形式的数）。
// 小红想知道，自己最少删几个字符可以达成？请你编写一个函数返回这个答案。
//1≤len(s)≤1051\leq len(s) \leq 10^51≤len(s)≤10

/**
 * 解题思路：首先观察2的幂规律：
 * 1, 10, 100, 1000, 10000....不难发现，2的幂二进制串只能允许出现一个1，并且在字符串的开头
 * 因此可以得到解决方案
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minCnt(string str){
        int count = 0;
        int count_1 = 0;
        int i = 0;
        for (; i < str.length(); i++) {
            if (str[i] != '1') {
                count++;
            } else {
                break;
            }
        }
        for (; i < str.length(); i++) {
            if (str[i] == '1') {
                count_1++;
            }
        }
        return count + (count_1 - 1);
    }
};

int main() {
    string str;
    cin>>str;
    Solution *pSolution = new Solution;
    int res = pSolution->minCnt(str);
    cout<<res<<endl;
    return 0;
}
