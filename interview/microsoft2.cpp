//
// Created by wangheng on 2022/8/19.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

string solution(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int a[10] = {0};
    for(int i = 0;i<S.size();i++){
        a[S[i] - '0']++;
    }
    deque<char> ans;
    for(int i = 0;i<10;i++){
        while(a[i]>=2){
            ans.push_front(i+'0');
            ans.push_back(i+'0');
            a[i]-=2;
        }
    }
    for(int i = 9;i>=0;i--){
        int size = ans.size();
        if(a[i]>=1){
            ans.insert(ans.begin()+size / 2, i+'0');
            break;
        }
    }
    string res = "";
    for(char c:ans){
        res.push_back(c);
    }
    int l = 0, r = res.size();
    for(int i = 0;i<res.size();i++){
        if(res[i]=='0'){
            l++;
            r--;
        }else{
            break;
        }
    }
    auto basicString = res.substr(l, r - l);
    if(res.size()>0 && basicString.size()==0){
        return "0";
    }
    return basicString;
}

int main() {
    string str = "3987888977899800000";
    string str1 = "00900";
    string str2 = "0000";
    string str3 = "54321";
    cout<<solution(str3)<<endl;
    return 0;
}
