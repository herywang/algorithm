//
// Created by wangheng on 2021/6/25.
// 字符串相乘

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2=="0"){
            return "0";
        }
        int len = num2.length();
        string tmp[len];
        // 做乘法
        for(int i = num2.size()-1;i>=0;i--){
            unsigned int _t = 0;    //进位
            string res = "";
            for(int k = 0;k<num2.size()-i-1;k++){
                res = res + '0';
            }
            for(int j =num1.size()-1;j>=0;j--){
                unsigned int _ = (int)(num1[j]-'0') * (int)(num2[i]-'0') + _t;
                if(_ > 9){
                    _t = _ / 10;
                    res = ((char)((_ % 10)+'0')) + res;
                }else{
                    res = (char)(_+'0') + res;
                    _t = 0;
                }
            }
            if(_t != 0){
                res = (char)(_t+'0') + res;
            }
            tmp[i] = res;
        }
        // 做加法
        int max_len = 0;
        for(int i = 0;i<num2.size();i++){
            if(tmp[i].size() > max_len)
                max_len = tmp[i].size();
        }
        // 长度补齐
        for(int i = 0;i<num2.size();i++){
            int _limit = max_len - tmp[i].size();
            for(int j = 0;j<_limit;j++){
                tmp[i] = '0'+tmp[i];
            }
        }
        unsigned int _t = 0;//进位
        string res = "";
        for(int i = max_len-1;i>=0;i--){
            unsigned int __t = 0;
            for(int j = 0;j<num2.size();j++){
                __t += (int)(tmp[j][i]-'0');
            }
            __t += _t;
            if(__t > 9){
                _t = __t / 10;
                __t = __t % 10;
            }else{
                _t = 0;
            }
            res = (char)(__t+'0') + res;
        }
        if(_t > 0){
            res = (char)(_t+'0') + res;
        }
        return res;
    }
};

int main() {
    auto s = new Solution;
    std::cout<<s->multiply("12345", "123")<<endl;
    return 0;
}
