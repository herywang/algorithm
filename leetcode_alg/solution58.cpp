//
// Created by wangheng on 2021/7/5.
// 求解最后一个单词长度

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string tmp = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] == ' ' && tmp != ""){
                words.push_back(tmp);
                tmp = "";
            }else if(s[i] != ' '){
                tmp.push_back(s[i]);
            }
        }
        if(tmp.length() != 0){
            words.push_back(tmp);
        }
        if(words.size() == 0){
            return 0;
        }else{
            return words[words.size()-1].length();
        }
    }
};

int main() {
    Solution* solution = new Solution;
    cout<<solution->lengthOfLastWord("a")<<endl;
    return 0;
}
