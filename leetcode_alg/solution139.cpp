//
// Created by wangheng on 2022/8/24.
// 单词拆分（动态规划）

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.length();
        int *dp = new int[n+1]{0};
        dp[0] = 1;
        for(int i = 0;i<n;i++){
            if(!dp[i]){
                continue;
            }
            for(auto &word: wordDict){
                if(word.size() + i <= n && s.substr(i, word.size()) == word){
                    dp[i+word.size()] =1;
                }
            }
        }
        return dp[n];
    }
};

void testSolution() {
    auto s = new Solution;
    string str = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout<<s->wordBreak(str, wordDict)<<endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}