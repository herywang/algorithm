//
// Created by wangheng on 2022/8/25.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int N) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    const string &basicString = to_string(N);
    vector<pair<int, int>> list;

    if(basicString[0] == '-'){
        // 负数
        for(int i = 1;i<basicString.size();i++){
            if(basicString[i] == '5'){
                pair<int, int> p;
                if(i>1){
                    p.first = i;
                    p.second = basicString[i-1] - '0';
                }else{
                    p.first = i;
                    p.second = -1;
                }
                list.emplace_back(p);
            }
        }
    }else{
        // 正数
        for(int i = 0;i<basicString.size();i++){
            if(basicString[i] == '5'){
                pair<int, int> p;
                if(i>0){
                    p.first = i;
                    p.second = basicString[i-1] - '0';
                }else{
                    p.first = i;
                    p.second = 0;
                }
                list.emplace_back(p);
            }
        }
        sort(list.begin(), list.end(), [](pair<int,int> p1, pair<int, int> p2){
            return p1.second > p2.second;
        });

        cout<<"hello world"<<endl;

    }

    cout<<basicString<<endl;
}


int main(int argc, char *argv[]) {
    solution(353452);
    //solution(-98745);
    return 0;
}