//
// Created by wangheng on 2022/8/17.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<string> getWords(string &s) {
        vector<string> ans;
        string tmpS = "";
        for (auto &c: s) {
            if (c == ' ') {
                if (tmpS != "") {
                    ans.push_back(tmpS);
                    tmpS.clear();
                }
            } else {
                tmpS.push_back(c);
            }
        }
        if (tmpS.size() > 0) {
            ans.push_back(tmpS);
        }
        return ans;
    }
public:
    bool wordPattern(string pattern, string s) {
        const vector<string> &words = getWords(s);
        if(words.size() != pattern.size()){
            return false;
        }
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        for(int i = 0;i<pattern.size();i++){
            if(map1.count(pattern[i]) && map2[words[i]] != pattern[i]){
                return false;
            }
            if(map2.count(words[i]) && map1[pattern[i]] != words[i]){
                return false;
            }
            map1[pattern[i]] = words[i];
            map2[words[i]] = pattern[i];
        }
        return true;
    }
};

void testSolution(){
    auto s = new Solution;
//    bool res = s->wordPattern("abba", "dog cat catt dog");
    bool res = s->wordPattern("abc", "dog cat dog");
    cout<<res<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
