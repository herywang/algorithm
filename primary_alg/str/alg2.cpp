//
// Created by wangheng on 2021/6/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        int index[26];
        for(int i = 0;i<s.size();i++){
            a[s[i] - 'a'] += 1;
            index[s[i]-'a'] = i;
        }
        for(int i = 0;i<s.size();i++){
            if(a[s[i]-'a']==1){
                return index[s[i]-'a'];
            }
        }
        return -1;
    }
};

int main() {
    Solution *solution = new Solution;
    cout<<solution->firstUniqChar("leetcode")<<endl;

    return 0;
}
