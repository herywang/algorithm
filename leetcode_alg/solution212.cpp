//
// Created by wangheng on 2022/7/23.
// 单词搜索

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        for (string word: words) {
            for (int x = 0; x < board.size(); x++) {
                for (int y = 0; y < board[0].size(); y++) {
                    if (search(board, word, 0, x, y)) {
                        res.push_back(word);
                        y = 0x7FFFFFFF; // break y
                        x = 0x7FFFFFFF; // break x
                    }
                }
            }
        }
        return res;
    }

    bool search(vector<vector<char>> &board, string &word, int index, int x, int y) {
        if (index == word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if (word[index] == board[x][y]) {
            char t = word[index];
            board[x][y] = '\0';
            bool res = search(board, word, index + 1, x - 1, y) ||
                       search(board, word, index + 1, x + 1, y) ||
                       search(board, word, index + 1, x, y - 1) ||
                       search(board, word, index + 1, x, y + 1);
            board[x][y] = t;
            return res;
        }
        return false;
    }
};

void testSolution() {
    auto s = new Solution;
//    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
//                                  {'e', 't', 'a', 'e'},
//                                  {'i', 'h', 'k', 'r'},
//                                  {'i', 'f', 'l', 'v'}};
    vector<vector<char>> board = {{'a', 'a'}};
    vector<string> words = {"aaa"};
    const vector<string> &res = s->findWords(board, words);
    for (string r: res) {
        cout << r << endl;
    }
    delete s;
}

int main() {
    testSolution();
    return 0;
}
