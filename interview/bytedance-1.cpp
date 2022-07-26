//
// Created by wangheng on 2022/7/26.
//

#include <iostream>
#include <vector>

using namespace std;

void solution(string &str){
    int n = str.length();
    for(int i = 0;i<n-1;i++){
        if(str[i] != str[i+1]){
            continue;
        }
        // 连续两个字符相等, str[i] == str[i+1]
        if(i+2 < n && str[i+2] == str[i]){
            // 连续三个字符相等
            str.erase(str.begin()+(i+2));
            n--;
            i--;
        }else if(i+3<n && str[i+3] == str[i+2]){
            // AABB型组合
            str.erase(str.begin() + (i+2));
            n--;
            i--;
        }
    }
}

int main() {
    int n;
    vector<string> str;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        str.emplace_back(s);
    }
    for(string s: str){
        solution(s);
        cout<<s<<endl;
    }
    return 0;
}
