//
// Created by wangheng on 2022/7/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length() < 10){
            return ans;
        }
        unordered_map<string, int> map;
        int n = s.size();
        for(int i = 0;i<=n-10;i++){
            string sub = s.substr(i, 10);
            map[sub] += 1;
            if(map[sub] == 2){
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
void testSolution(){
    auto s = new Solution;
    auto sequences = s->findRepeatedDnaSequences("AAAAAAAAAAA");
    for(int i = 0;i<sequences.size();i++){
        cout<<sequences[i]<<endl;
    }
}
int main() {
    testSolution();
    return 0;
}
