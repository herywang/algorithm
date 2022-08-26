//
// Created by wangheng on 2022/8/25.
// 最大正方形

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if(matrix.size()==0){
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int dp[row][col];
        int ans = 0;
        for(int i = 0;i<row;i++){
            if(matrix[i][0] == 1){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }
        }
        for(int i = 0;i<col;i++){
            if(matrix[0][i] == 1){
                dp[0][i] = 1;
            }else{
                dp[0][i] = 0;
            }
        }
        for(int i = 1;i<row;i++){
            for(int j = 1;j<col;j++){
                if(matrix[i][j] == 1) {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

void testSolution(){
    auto s = new Solution;
    vector<vector<char>> matrix = {{1,0,1,0,0},
                                  {1,0,1,1,1},
                                  {1,1,1,1,1},
                                  {1,0,0,1,0}};
    int l = s->maximalSquare(matrix);
    cout<<l*l<<endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}