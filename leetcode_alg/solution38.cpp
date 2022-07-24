//
// Created by wangheng on 2021/6/21.
// 外观数列问题, 后一项数字是对前一项的描述
#include "iostream"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n<1 || n > 30){
            return "";
        }
        if(n < 2)
            return "1";
        string current = "1";
        char currentDigit;
        int num;
        for(int i = 2;i<=n;i++){
            string newStr = "";
            // 初始化
            currentDigit = current[0];
            num = 1;
            int j = 1;
            while(j<current.size()){
                if(current[j] == currentDigit){
                    num++;
                }else{
                    newStr.push_back(num+'0');
                    newStr.push_back(currentDigit);
                    currentDigit = current[j];
                    num = 1;
                }
                j++;
            }
            newStr.push_back(num+'0');
            newStr.push_back(currentDigit);
            current = newStr;
        }
        return current;
    }
};

int main(){
    Solution* solution = new Solution;
    const string &say = solution->countAndSay(5);
    cout<<say<<endl;
    return 0;
}

