//
// Created by wangheng on 2022/6/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// todo
vector<int> findSubstring(string s, vector<string>& words){
    vector<int> res;
    if(words.size() == 0){
        return res;
    }
    unordered_map<string, int> m1;
    for(string word:words){
        if(m1[word] != NULL){
            m1[word] = m1[word]+1;
        }else{
            m1[word] = 1;
        }
    }


}

int main() {

    return 0;
}
