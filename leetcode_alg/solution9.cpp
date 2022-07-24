//
// Created by wangheng on 2021/6/17.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }else{
            const string &str = to_string(x);
            const unsigned int len = str.length();
            for(int i = 0;i<len/2;i++){
                if(str[i] != str[len-i-1]){
                    return false;
                }
            }
            return true;
        }

    }
};
int main(){
    Solution *s = new Solution;
    cout<<s->isPalindrome(1073773701)<<endl;
    return 0;
}

