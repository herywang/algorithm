//
// Created by wangheng on 2022/7/7.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * @param num 物品数量
 * @param weights 重量
 * @param values 价值
 * @param capacity 背包剩余容积
 * @return 能装的最大价值
 */
int maxValues(int num, int *weights, int *values, int capacity){
    int dp[num][capacity];
    // 数组置0
    for(int i = 0;i<num;i++){
        memset(dp[i], 0, sizeof(int)*capacity);
    }
    

    return 0;
}

int main() {
    int num = 0;
    int capacity = 0;
    std::vector<unsigned char> buf;
    cout<<buf.size()<<endl;
    cout<<"请输入物品数量"<<endl;
    cin>>num;
    cout<<"请输入背包容积"<<endl;
    cin>>capacity;
    cout<<"请输入每个物品的重量"<<endl;
    int *weights = new int[num];
    int *values = new int[num];
    for(int i = 0;i<num;i++){
        cin>>weights[i];
    }
    cout<<"请输入每个物品的价值"<<endl;
    for(int i = 0;i<num;i++){
        cin>>values[i];
    }

    for(int i = 0;i<num;i++){
        cout<<weights[i]<<"-";
    }
    cout<<endl;
    return 0;
}
