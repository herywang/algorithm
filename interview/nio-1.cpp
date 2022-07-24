//
// Created by wangheng on 2022/7/17.
//

#include <iostream>
#include <vector>

using namespace std;


bool check(vector<int> & exam){
    for(int i = 0;i<exam.size()-1;i++){
        for(int j = i+1;j<exam.size();j++){
            int m = abs(exam[i] - exam[j]);
            if(std::find(exam.begin(),exam.end(), m) == exam.end()){
                // 不存在m
                exam.push_back(m);
                return true;
            }
        }
    }
    return false;
}

void solution(vector<vector<int>> & example){
    for(int i = 0;i<example.size();i++){
        vector<int> ex = example[i];
        int j = 0;
        while(true){
            if(check(ex)){
                // 不存在, 小A没输，轮到小B操作
                j++;
            }else{
                // 存在，小A输了
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
    for(int i = 0;i<T;i++){
        int a, b;
        cin>>a>>b;
        vector<int> t;
        t.push_back(a);
        t.push_back(b);
        example.push_back(t);
    }
    solution(example);
    return 0;
}
