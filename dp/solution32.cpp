//
// Created by wangheng on 2021/7/4.
// 最长有效括号, 动态规划算法

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() < 2){
            return 0;
        }
        int len = s.length();
        vector<int> dp(len, 0);
        int maxVal = INT32_MIN;
        for(int i = 1;i<len;i++){
            if(s[i] == '('){
                dp[i] = 0;
            }else{
                if(s[i-1] == '('){
                    // 第一种情况
                    if(i-2>=0){
                        dp[i] = dp[i-2] + 2;
                    }else{
                        dp[i] = 2;
                    }
                }else if(dp[i-1] > 0){
                    // 第二种情况 s[i-1] = ')', 需要考虑到s[i-1] 配对情况
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                        dp[i] = dp[i-1] + 2;
                        if(i-dp[i-1]-2 >= 0 ){
                            dp[i] = dp[i] + dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};

int main() {
    Solution* s = new Solution;
//    string str = "()()((()())(()((";
    string str = ")()())";
    cout<<s->longestValidParentheses(str)<<endl;
    return 0;
}
