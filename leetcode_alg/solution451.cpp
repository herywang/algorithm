//
// Created by wangheng on 2022/8/21.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<char, int>> vec;
        string ans;
        for (auto &c: s) {
            mp[c]++;
        }
        for (auto &it: mp) {
            vec.emplace_back(it);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> p1, const pair<char, int> p2) {
            return p1.second > p2.second;
        });
        for(auto &p:vec){
            while(p.second>0){
                ans.push_back(p.first);
                p.second--;
            }
        }
        return ans;
    }
};

int main() {
    auto s = new Solution;
    string test = "Aabb";
    cout<<s->frequencySort(test)<<endl;
    delete s;
    return 0;
}