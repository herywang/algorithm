//
// Created by wangheng on 2021/6/24.
// 字母异位词： 相同字母组成的排序不同的单词

#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0;i<s.size();i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution* solution = new Solution;
    cout<<solution->isAnagram("anagram","nagaram")<<endl;
    return 0;
}
