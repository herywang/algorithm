//
// Created by wangheng on 2021/7/17.
// 二进制相加 (转换成整数容易溢出)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()){
            return b;
        }
        if(b.empty()){
            return a;
        }
        // 字符串对其
        int limit;
        if(a.length() > b.length()){
            limit = a.length() - b.length();
            for(int i = 0;i<limit;i++){
                b = "0"+b;
            }
        }else{
            limit = b.length() - a.length();
            for(int i = 0;i<limit;i++){
                a = "0"+a;
            }
        }
        int c = 0;//进位
        for(int i = a.length()-1;i>=0;i--){
            int t = a[i]-'0'+b[i]-'0' + c;
            if( t >= 2){
                a[i] = (char)(t%2 + '0');
                c = 1;
            }else{
                a[i] = (char)(t+'0');
                c = 0;
            }
        }
        if(c == 1){
            a = '1' + a;
        }
        return a;
    }
};

int main() {
    string a = "1";
    string b = "111";
    Solution *pSolution = new Solution;
    cout<<pSolution->addBinary(a, b)<<endl;
    delete pSolution;
    return 0;
}
