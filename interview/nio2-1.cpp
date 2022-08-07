//
// Created by wangheng on 2022/7/31.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(vector<int> &exam){
    set<int> s;
    int l = exam.size();
    for(int i = 0;i<l;i++){
        s.insert(exam[i]);
    }
    for(int i = 0;i<l-1;i++){
        for(int j = i+1;j<l;j++){
            int m = abs(exam[i] - exam[j]);
            if(s.find(m)==s.end()){
                // 不存在 m，添加到集合中
                exam.emplace_back(m);
                return true;
            }
        }
    }
    return false;
}

void solution(vector<vector<int>> &example){
    for(int i = 0;i<example.size();i++){
        vector<int> ex = example[i];
        int j = 0;
        while(true){
            if(check(ex)){
                j++;
            }else{
                break;
            }
        }
        if(j % 2 == 0){
            cout<<"B"<<endl;
        }else{
            cout<<"A"<<endl;
        }
    }
}

int main() {
    int T;
    cin>>T;
    vector<vector<int>> example;
    for(int i= 0;i<T;i++){
        int a, b;
        cin>>a>>b;
        vector<int> t;
        t.emplace_back(a);
        t.emplace_back(b);
        example.emplace_back(t);
    }
    solution(example);
    return 0;
}
