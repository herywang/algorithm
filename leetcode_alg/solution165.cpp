//
// Created by wangheng on 2022/7/20.
// 比较版本号

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start = 0;
        vector<int> v1;
        vector<int> v2;
        for (int i = 1; i < version1.length(); i++) {
            if (version1[i] == '.') {
                auto subStr = version1.substr(start, i - start);
                auto i1 = atoi(subStr.c_str());
                v1.push_back(i1);
                start = i + 1;
            }
        }
        v1.push_back(atoi(version1.substr(start, version1.length() - start).c_str()));
        start = 0;
        for (int i = 1; i < version2.length(); i++) {
            if (version2[i] == '.') {
                auto subStr = version2.substr(start, i - start);
                auto i1 = atoi(subStr.c_str());
                v2.push_back(i1);
                start = i + 1;
            }
        }
        v2.push_back(atoi(version2.substr(start, version2.length() - start).c_str()));

        if (v1.size() < v2.size()) {
            auto i1 = v2.size() - v1.size();
            for (int i = 0; i < i1; i++) {
                v1.push_back(0);
            }
        }else if(v1.size() > v2.size()){
            unsigned long i1 = v1.size() - v2.size();
            for(int i = 0;i<i1;i++){
                v2.push_back(0);
            }
        }

        for(int i = 0;i<v1.size();i++){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v2[i] > v1[i]){
                return -1;
            }else{
                continue;
            }
        }
        return 0;
    }
};

void testSolution(){
    auto s = new Solution;
    cout<<s->compareVersion("1.0", "1.0.0")<<endl;
}

int main() {
    testSolution();
    return 0;
}
