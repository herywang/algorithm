//
// Created by wangheng on 1/5/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len2 > len1){
            return -1;
        }
        if(len2 == len1){
            if(haystack == needle){
                return 0;
            }else{
                return -1;
            }
        }
        int start = 0;
        int mov;
        while (start < len1 - len2 + 1) {
            mov = start;
            bool isMatch = true;
            while (mov < start + len2){
                if(haystack[mov] != needle[mov - start]){
                    isMatch = false;
                    break;
                }else{
                    mov ++;
                }
            }
            if(isMatch){
                return start;
            }
            start ++;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    auto s = new Solution;
    int res = s->strStr("leetcode", "tco");
    cout<<"结果是："<<res;
    delete s;
    return 0;
}