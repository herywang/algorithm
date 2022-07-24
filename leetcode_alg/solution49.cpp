//
// Created by wangheng on 2021/6/25.
// 字母异位词分组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0)
            return result;
        for(int i = 0;i<strs.size();i++){
            sort(strs[i].begin(), strs[i].end());
        }
        sort(strs.begin(),  strs.end());
        string latest = "";
        vector<string> _res;
        for(string s:strs){
            if(s != latest && latest != "" && !_res.empty()){
                vector<string> r(_res);
                result.push_back(r);
                _res.clear();
            }else{
                _res.push_back(s);
                latest = s;
            }
        }
        return result;
    }
};

int main() {
    auto s = new Solution;
    vector<string> strs = {"abc","dfr","cab", "ddd", "rdf"};
    const vector<vector<string>> &results = s->groupAnagrams(strs);
    for(vector<string> _strs:results){
        for(string ss:_strs){
            cout<<ss<<endl;
        }
    }
    return 0;
}
