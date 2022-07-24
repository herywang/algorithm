//
// Created by wangheng on 2022/7/3.
// 下一个更大的元素

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        if(n <= 0) return -1;
        stringstream ss;
        ss << n;
        string n_str = ss.str();
        int len = n_str.length();
        int i = len-1;
        for(;i>=0;i--){
            if(i == 0){
                return -1;
            }
            if(n_str[i] > n_str[i-1]){
                break;
            }
        }
        // 找到相对生序后, 对后半部分进行生序排列
        for(int k = i;k<len;k++){
            for(int j = i;j<len-(k-i)-1;j++){
                if(n_str[j] > n_str[j+1]){
                    char t = n_str[j];
                    n_str[j] = n_str[j+1];
                    n_str[j+1] = t;
                }
            }
        }
        // 从升序排列中找到第一个比第i-1元素大的值，来进行交换
        for(int k = i;k<len;k++){
            if(n_str[k] > n_str[i-1]){
                char t = n_str[k];
                n_str[k] = n_str[i-1];
                n_str[i-1] = t;
                break;
            }
        }
        try {
            return stoi(n_str);
        }catch(...){
            return -1;
        }
    }
};

int main() {
    Solution *s = new Solution;
    int res = s->nextGreaterElement(12443322);
    cout << res << endl;
    return 0;
}
