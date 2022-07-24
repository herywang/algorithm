//
// Created by wangheng on 2022/7/21.
// 同构字符串

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.length(); i++) {
            if (map1.find(s[i]) == map1.end() ) {
                // map集合中没有找到, 则建立字符映射关系
                map1[s[i]] = t[i];
            }else{
                if (map1[s[i]] != t[i]) {
                    return false;
                }
                continue;
            }
            if(map2.find(t[i]) == map2.end()){
                map2[t[i]] = s[i];
            }else{
                if(map2[t[i]] != s[i]){
                    return false;
                }
                continue;
            }
        }
        return true;
    }
};

void testSolution() {
    auto s = new Solution;
    cout << s->isIsomorphic("aaeaa", "uuxyy") << endl;
}

int main() {
    testSolution();
    return 0;
}
