//
// Created by wangheng on 2021/6/17.
// 石子游戏
#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        int sum = this->sum(piles);
        if (sum % 2 == 0) {
            cerr << "石子数量为偶数,不合法" << endl;
            return false;
        } else if (piles.size() < 2 || piles.size() > 500 || piles.size() % 2 != 0) {
            cerr << "石子堆数不合法" << endl;
        } else {
            int res = 0;
            unsigned int len = piles.size();
            int l = 0;
            unsigned int r = len - 1;
            for (int i = 0; i < len/2;i++) {
                if (piles[l] > piles[r]) {
                    res += piles[l];
                    l++;
                } else {
                    res += piles[r];
                    r--;
                }
            }
            if(res >= sum / 2){
                return true;
            }
            return false;
        }
    }

private:
    inline int sum(vector<int> &arrs) {
        int res = 0;
        for (int a: arrs) {
            res += a;
        }
        return res;
    }
};


int main() {
    int a = -1;
    int b = 1;
    cout<<(a<<31)<<endl;
    return 0;
}
