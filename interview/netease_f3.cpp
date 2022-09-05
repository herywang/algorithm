/**
 * @file netease_f3.cpp
 * @author your name (you@domain.com)
 * @brief 画笔题目
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include "vec_util.h"

using namespace std;
/**
 * @brief
 *
 * @param w 多少个格子
 * @param n 多少只画笔
 * @param a 每只画笔能涂抹多少个格子
 * @param start 开始涂抹位置
 * @param _c 当前画笔的索引
 * @return vector<string> 返回结果
 */
void solution(int w, int n, int *a, int start, int _c, string &path, vector<string> &ans) {
    if (start >= w) {
        return;
    }
    if (start + a[_c] > w) {
        return;
    }
    if (_c >= n) {
        //画笔用完了
        return;
    }
    for (int i = start; i < w; i++) {
        if (w - i < a[_c]) {
            //如果剩余的格子数量少于画笔能够涂抹的格子数量, 直接返回
            break;
        }
        // [start, i]之间用白色填充
        for (int k = start; k < i; k++) {
            path.push_back('0');
        }
        for (int j = i; j < a[_c]; j++) {
            path.push_back(_c + '1');
        }
        if (path.size() == w && _c == n - 1) {
            ans.push_back(path);
        }
        solution(w, n, a, i + a[_c] + 1, _c + 1, path, ans);

        for (int j = i; j < a[_c]; j++) {
            path.pop_back();
        }
        for (int k = start; k < i; k++) {
            path.pop_back();
        }
    }
}

int main() {
    int w; //方格数量
    int n; //画笔数量
    cin >> w >> n;
    int *a = new int[n]; // a[i]表示第i个画笔能花多少个格子
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> ans;
    for (int i = 0; i < w; i++) {
        string path;
        for (int j = 0; j < i; j++) {
            path.push_back('0');
        }
        solution(w, n, a, i, 0, path, ans);
        if (path.size() < w) {
            for (int j = 0; j < w - path.size(); j++) {
                path.push_back('0');
            }
        }
    }
    print_vec(ans);
    return 0;
}