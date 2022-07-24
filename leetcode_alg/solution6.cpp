//
// Created by wangheng on 2021/10/10.
// Z字形变换

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2)return s;
        string str[numRows];
        int flag = -1;
        int row = 0;
        for(int i = 0;i<s.size();i++){
            str[row] += s[i];
            if(row==numRows-1 || row==0)flag = -flag;
            row += flag;
        }
        string res;
        for(int i = 0;i<numRows;i++){
            res += str[i];
        }
        return res;
    }
};

int main() {
    auto s = new Solution;
    cout<<s->convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}
