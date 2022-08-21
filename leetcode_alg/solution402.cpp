//
// Created by wangheng on 2022/8/21.
// 删除k位数字, 返回最小的数

#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> s;
        int popCount = 0;
        for(auto &c: num){
            while (!s.empty() && c<s.back() && popCount < k){
                s.pop_back();
                popCount++;
            }
            s.push_back(c);
        }
        while (popCount<k){
            s.pop_back();
            popCount++;
        }
        string ans = "";
        while (!s.empty()){
            auto c = s.front();
            s.pop_front();
            if(ans.empty() && c=='0'){
                continue;
            }
            ans.push_back(c);
        }
        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};

int main(int argc, char *argv[]){
    auto s = new Solution;
    string num = "10";
    cout<<s->removeKdigits(num, 2)<<endl;
    delete s;
    return 0;
}

