//
// Created by wangheng on 2022/7/19.
// 不同的二叉搜索数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n<=1){
            return n;
        }
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;
        for(int _n = 2; _n <= n; _n++){
            for(int i = 1; i <= _n; i++){
                G[_n] += G[i - 1] * G[_n - i];
            }
        }
        return G[n];
    }
};
void testSolution(){
    Solution *s = new Solution;
    cout<<s->numTrees(3)<<endl;
    delete s;
}
int main() {
testSolution();
    return 0;
}
