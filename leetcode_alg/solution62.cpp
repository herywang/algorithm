//
// Created by wangheng on 2022/8/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n<1){
            return 0;
        }
        int dp[m][n];
        for(int i = 0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int i = 0;i<n;i++){
            dp[0][i] = 1;
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

void testSolution(){
    auto s = new Solution;
    cout<<s->uniquePaths(3, 7)<<endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}