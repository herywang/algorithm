//
// Created by wangheng on 2022/7/19.
// n皇后问题

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n <= 0) {
            return res;
        }
        // 定义三个集合，分别用于标识：当前列、左上->右下，右上->左下是否存在皇后
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;

        // 定义一个一位数组，标识第i行的皇后位置
        int *queue = new int[n]{0};
        dfs(queue, res, n, 0, columns, diagonals1, diagonals2);
        return res;
    }

    void dfs(int *queue, vector<vector<string>> &res, int n, int currentRow, unordered_set<int> &columns,
             unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (currentRow == n) {
            const vector<string> &board = generateBoard(queue, n);
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            // 当前列中已经被一个皇后占领了
            if (columns.find(i) != columns.end()) {
                continue;
            }
            // 右斜线被一个皇后占领
            int diagonal1 = currentRow - i;
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }
            // 左斜线被一个皇后占领
            int diagonal2 = currentRow + i;
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }
            queue[currentRow] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            dfs(queue, res, n, currentRow + 1, columns, diagonals1, diagonals2);
            queue[currentRow] = 0;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }

    vector<string> generateBoard(int queue[], int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queue[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

void testSolution() {
    auto s = new Solution;
    const vector<vector<string>> &res = s->solveNQueens(4);
    for (const vector<string> &s: res) {
        for(const string &str: s){
            cout<<str<<endl;
        }
        cout<<"---------"<<endl;
    }
}
int main() {
    testSolution();
    return 0;
}
