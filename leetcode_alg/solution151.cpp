//
// Created by wangheng on 2022/7/20.
//

#include <iostream>
#include <vector>
#include "vec_util.h"
#include <regex>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        std::string res = "";
        std::regex r("\\s+");
        std::sregex_token_iterator pos(s.begin(), s.end(),r,-1);
        decltype(pos) end;
        for(;pos != end;++pos){
            if(pos->str() != ""){
                words.emplace_back(pos->str());
            }
        }
        for(int i = words.size()-1;i>=0;i--){
            res += words[i];
            if(i != 0){
                res += " ";
            }
        }
        return res;
    }
};

void testSolution(){
    Solution *pSolution = new Solution;
    cout<<pSolution->reverseWords(" the sky is blue ")<<endl;
}

int main() {
    testSolution();
    return 0;
}
